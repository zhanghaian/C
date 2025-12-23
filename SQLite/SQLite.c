#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TABLES 10           // 一个数据库最大表数量
#define MAX_COLUMNS 10          // 一个表最大列数量
#define MAX_RECORDS 100         // 一个表最大记录数量
#define MAX_NAME_LEN 32         // 名称最大长度
#define MAX_TEXT_LEN 128        // 文本最大长度

//支持的数据类型
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_TEXT,
    TYPE_DATETIME
} ColumnType;

//列定义（字段信息）
typedef struct {
    char name[MAX_NAME_LEN];        // 字段名如"id", "name"
    ColumnType type;                // 字段类型
} ColumnDef;

//数据行（记录）
typedef struct {
    char values[MAX_COLUMNS][MAX_TEXT_LEN]; // 存储每一列的数值（字符串形式）
    int is_deleted;                         // 标记位是否被删除
} Row;

//表定义
typedef struct {
    char name[MAX_NAME_LEN];            // 表名如"users", "orders"
    int column_count;                   // 列数量
    ColumnDef columns[MAX_COLUMNS];     // 列定义数组
    int record_count;                   // 记录数量
    Row records[MAX_RECORDS];           // 记录数组
} Table;

//数据库整体结构
typedef struct {
    char name[MAX_NAME_LEN];            // 数据库名
    int table_count;                    // 表数量
    Table tables[MAX_TABLES];           // 表数组
} Database;

//全局变量，表示打开当前的数据库
Database *current_db = NULL;

int main() {

}