#ifndef _c_
#define _c_
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char *DataStr;
typedef int DataInt;
typedef float DataFloat;
typedef char DataCharacter;
typedef bool DataBool;

struct CsvPoints
{
    int rows;
    int coloumns;
};

enum IDS
{
    CSV_OK = 0,
    CSV_ERROR = -1,
    CSV_INVALID = -2,
    CSV_SUCCESS = 1,
    CSV_BLOCKED = -3,
    CSV_WRITER_OK = 2,
    CSV_READER_OK = 3,
    CSV_WRITER_FAIL = -4,
    CSV_READER_FAIL = -5
};

DataStr *ReadDataCSV(char *filename, struct CsvPoints SetWhere, DataStr RowName, DataStr ColoumnName);