#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_COLS 20
#define MAX_ROWS 1000
#define MAX_NAME 50
#define MAX_VALUE 100

// 数据类型枚举
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_TEXT,
    TYPE_DATETIME
} DataType;

// 列定义
typedef struct {
    char name[MAX_NAME];
    DataType type;
} Column;

// 数据行
typedef struct {
    char values[MAX_COLS][MAX_VALUE];
} Row;

// 数据表
typedef struct {
    char name[MAX_NAME];
    Column cols[MAX_COLS];
    int col_count;
    Row rows[MAX_ROWS];
    int row_count;
} Table;

// 数据库
typedef struct {
    char name[MAX_NAME];
    Table tables[MAX_TABLES];
    int table_count;
} Database;

Database db;
int db_opened = 0;

// 函数声明
void cmd_open(char *dbname);
void cmd_save(char *dbname);
void cmd_drop(char *dbname);
void cmd_tables();
void cmd_quit();
void cmd_create_table(char *input);
void cmd_drop_table(char *tablename);
void cmd_info_table(char *tablename);
void cmd_insert(char *input);
void cmd_select(char *input);
void cmd_delete(char *input);
Table* find_table(char *name);
void trim(char *str);

int main() {
    char input[500];
    
    printf("简易文件数据库系统\n");
    printf("输入 .help 查看帮助\n\n");
    
    while (1) {
        printf("db> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        
        // 去除换行符
        input[strcspn(input, "\n")] = 0;
        trim(input);
        
        if (strlen(input) == 0) continue;
        
        // 系统命令（以.开头）
        if (input[0] == '.') {
            if (strncmp(input, ".open ", 6) == 0) {
                cmd_open(input + 6);
            } else if (strncmp(input, ".save ", 6) == 0) {
                cmd_save(input + 6);
            } else if (strncmp(input, ".drop ", 6) == 0) {
                cmd_drop(input + 6);
            } else if (strcmp(input, ".tables") == 0) {
                cmd_tables();
            } else if (strcmp(input, ".quit") == 0) {
                cmd_quit();
                break;
            } else if (strcmp(input, ".help") == 0) {
                printf("系统命令:\n");
                printf("  .open <dbname>  - 打开数据库\n");
                printf("  .save <dbname>  - 保存数据库\n");
                printf("  .drop <dbname>  - 删除数据库\n");
                printf("  .tables         - 列出所有表\n");
                printf("  .quit           - 退出\n");
                printf("\nSQL命令:\n");
                printf("  create table ... - 创建表\n");
                printf("  drop table ...   - 删除表\n");
                printf("  info table ...   - 显示表信息\n");
                printf("  insert into ...  - 插入数据\n");
                printf("  select ...       - 查询数据\n");
                printf("  delete from ...  - 删除数据\n");
            } else {
                printf("未知命令\n");
            }
        }
        // SQL命令
        else if (strncmp(input, "create table", 12) == 0) {
            cmd_create_table(input);
        } else if (strncmp(input, "drop table", 10) == 0) {
            cmd_drop_table(input + 11);
        } else if (strncmp(input, "info table", 10) == 0) {
            cmd_info_table(input + 11);
        } else if (strncmp(input, "insert into", 11) == 0) {
            cmd_insert(input);
        } else if (strncmp(input, "select", 6) == 0) {
            cmd_select(input);
        } else if (strncmp(input, "delete from", 11) == 0) {
            cmd_delete(input);
        } else {
            printf("未知SQL命令\n");
        }
    }
    
    return 0;
}

// 去除字符串首尾空格
void trim(char *str) {
    int i, j = 0;
    int len = strlen(str);
    
    // 去除前导空格
    for (i = 0; i < len && str[i] == ' '; i++);
    
    // 移动字符
    while (i < len) {
        str[j++] = str[i++];
    }
    str[j] = '\0';
    
    // 去除尾部空格
    for (i = j - 1; i >= 0 && str[i] == ' '; i--) {
        str[i] = '\0';
    }
}

// 打开数据库
void cmd_open(char *dbname) {
    trim(dbname);
    FILE *fp = fopen(dbname, "rb");
    
    if (fp) {
        fread(&db, sizeof(Database), 1, fp);
        fclose(fp);
        printf("数据库 '%s' 已打开\n", dbname);
    } else {
        // 创建新数据库
        strcpy(db.name, dbname);
        db.table_count = 0;
        printf("创建新数据库 '%s'\n", dbname);
    }
    db_opened = 1;
}

// 保存数据库
void cmd_save(char *dbname) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    trim(dbname);
    FILE *fp = fopen(dbname, "wb");
    if (fp) {
        fwrite(&db, sizeof(Database), 1, fp);
        fclose(fp);
        printf("数据库已保存为 '%s'\n", dbname);
    } else {
        printf("错误: 无法保存数据库\n");
    }
}

// 删除数据库
void cmd_drop(char *dbname) {
    trim(dbname);
    if (remove(dbname) == 0) {
        printf("数据库 '%s' 已删除\n", dbname);
    } else {
        printf("错误: 无法删除数据库\n");
    }
}

// 列出所有表
void cmd_tables() {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    printf("表列表:\n");
    for (int i = 0; i < db.table_count; i++) {
        printf("  %s\n", db.tables[i].name);
    }
}

// 退出
void cmd_quit() {
    if (db_opened) {
        char choice;
        printf("是否保存数据库? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            cmd_save(db.name);
        }
    }
    printf("再见!\n");
}

// 创建表
void cmd_create_table(char *input) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    char tablename[MAX_NAME];
    char *p = strstr(input, "table") + 6;
    
    // 提取表名
    sscanf(p, "%s", tablename);
    
    // 检查表是否已存在
    if (find_table(tablename)) {
        printf("错误: 表 '%s' 已存在\n", tablename);
        return;
    }
    
    Table *t = &db.tables[db.table_count];
    strcpy(t->name, tablename);
    t->col_count = 0;
    t->row_count = 0;
    
    // 解析列定义
    p = strchr(p, '(');
    if (!p) {
        printf("错误: 语法错误\n");
        return;
    }
    
    p++;
    char *end = strchr(p, ')');
    if (!end) {
        printf("错误: 语法错误\n");
        return;
    }
    *end = '\0';
    
    // 分割列定义
    char *token = strtok(p, ",");
    while (token && t->col_count < MAX_COLS) {
        trim(token);
        char colname[MAX_NAME], coltype[MAX_NAME];
        sscanf(token, "%s %s", colname, coltype);
        
        strcpy(t->cols[t->col_count].name, colname);
        
        if (strcmp(coltype, "int") == 0) {
            t->cols[t->col_count].type = TYPE_INT;
        } else if (strcmp(coltype, "float") == 0) {
            t->cols[t->col_count].type = TYPE_FLOAT;
        } else if (strcmp(coltype, "text") == 0) {
            t->cols[t->col_count].type = TYPE_TEXT;
        } else if (strcmp(coltype, "datetime") == 0) {
            t->cols[t->col_count].type = TYPE_DATETIME;
        }
        
        t->col_count++;
        token = strtok(NULL, ",");
    }
    
    db.table_count++;
    printf("表 '%s' 创建成功\n", tablename);
}

// 删除表
void cmd_drop_table(char *tablename) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    trim(tablename);
    // 去除分号
    tablename[strcspn(tablename, ";")] = 0;
    
    for (int i = 0; i < db.table_count; i++) {
        if (strcmp(db.tables[i].name, tablename) == 0) {
            // 移动后续表
            for (int j = i; j < db.table_count - 1; j++) {
                db.tables[j] = db.tables[j + 1];
            }
            db.table_count--;
            printf("表 '%s' 已删除\n", tablename);
            return;
        }
    }
    printf("错误: 表 '%s' 不存在\n", tablename);
}

// 显示表信息
void cmd_info_table(char *tablename) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    trim(tablename);
    tablename[strcspn(tablename, ";")] = 0;
    
    Table *t = find_table(tablename);
    if (!t) {
        printf("错误: 表 '%s' 不存在\n", tablename);
        return;
    }
    
    printf("表 '%s' 信息:\n", tablename);
    printf("字段数: %d\n", t->col_count);
    printf("记录数: %d\n", t->row_count);
    printf("\n字段列表:\n");
    
    const char *type_names[] = {"int", "float", "text", "datetime"};
    for (int i = 0; i < t->col_count; i++) {
        printf("  %s : %s\n", t->cols[i].name, type_names[t->cols[i].type]);
    }
}

// 插入数据
void cmd_insert(char *input) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    char tablename[MAX_NAME];
    char *p = strstr(input, "into") + 5;
    sscanf(p, "%s", tablename);
    
    Table *t = find_table(tablename);
    if (!t) {
        printf("错误: 表 '%s' 不存在\n", tablename);
        return;
    }
    
    if (t->row_count >= MAX_ROWS) {
        printf("错误: 表已满\n");
        return;
    }
    
    // 提取值
    p = strchr(p, '(');
    if (!p) {
        printf("错误: 语法错误\n");
        return;
    }
    
    p++;
    char *end = strchr(p, ')');
    if (!end) {
        printf("错误: 语法错误\n");
        return;
    }
    *end = '\0';
    
    Row *row = &t->rows[t->row_count];
    int col_idx = 0;
    
    // 分割值（处理单引号包围的字符串）
    while (*p && col_idx < t->col_count) {
        trim(p);
        if (*p == '\'') {
            p++;
            char *quote_end = strchr(p, '\'');
            if (quote_end) {
                *quote_end = '\0';
                strcpy(row->values[col_idx], p);
                p = quote_end + 1;
            }
        } else {
            char *comma = strchr(p, ',');
            if (comma) {
                *comma = '\0';
                trim(p);
                strcpy(row->values[col_idx], p);
                p = comma + 1;
            } else {
                trim(p);
                strcpy(row->values[col_idx], p);
                break;
            }
        }
        col_idx++;
        
        // 跳过逗号
        while (*p == ',' || *p == ' ') p++;
    }
    
    t->row_count++;
    printf("插入成功\n");
}

// 查询数据（简化版，仅支持单条件where）
void cmd_select(char *input) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    char tablename[MAX_NAME];
    char *p = strstr(input, "from") + 5;
    sscanf(p, "%s", tablename);
    
    Table *t = find_table(tablename);
    if (!t) {
        printf("错误: 表 '%s' 不存在\n", tablename);
        return;
    }
    
    // 打印表头
    for (int i = 0; i < t->col_count; i++) {
        printf("%-15s", t->cols[i].name);
    }
    printf("\n");
    for (int i = 0; i < t->col_count * 15; i++) printf("-");
    printf("\n");
    
    // 打印数据（简化版，不处理where条件）
    for (int i = 0; i < t->row_count; i++) {
        for (int j = 0; j < t->col_count; j++) {
            printf("%-15s", t->rows[i].values[j]);
        }
        printf("\n");
    }
    
    printf("\n共 %d 条记录\n", t->row_count);
}

// 删除数据（简化版）
void cmd_delete(char *input) {
    if (!db_opened) {
        printf("错误: 未打开数据库\n");
        return;
    }
    
    char tablename[MAX_NAME];
    char *p = strstr(input, "from") + 5;
    sscanf(p, "%s", tablename);
    
    Table *t = find_table(tablename);
    if (!t) {
        printf("错误: 表 '%s' 不存在\n", tablename);
        return;
    }
    
    // 简化版：删除所有记录
    int old_count = t->row_count;
    t->row_count = 0;
    printf("已删除 %d 条记录\n", old_count);
}

// 查找表
Table* find_table(char *name) {
    for (int i = 0; i < db.table_count; i++) {
        if (strcmp(db.tables[i].name, name) == 0) {
            return &db.tables[i];
        }
    }
    return NULL;
}