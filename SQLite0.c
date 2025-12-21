#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_COLS 20
#define MAX_ROWS 1000
#define MAX_NAME 50
#define MAX_VALUE 100

typedef enum {
    TYPE_IN,
    TYPE_FLOAT,
    TYPE_TEXT,
    TYPE_DATETIME
} DataType;

typedef struct {
    char name[MAX_NAME];
    DataType type;
} Column;
