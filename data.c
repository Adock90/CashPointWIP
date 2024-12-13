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
typedef char DataArray[];

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

char *ReadDataCSV(char *filename, struct CsvPoints SetWhere, DataStr RowName)
{
    FILE *file;

    char *arr[] = {""};

    file = fopen(filename, "r");

    char buffer[1024];

    DataInt row = 0;
    DataInt coloumn = 0;

    while (fgets(buffer, 1024, file))
    {
        row++;
        coloumn = 0;
        char *value = strtok(buffer, " ");

        int i = 0;

        while (value)
        {
            arr[i] = value;
            i++;

            value = strtok(NULL, " ");
            coloumn++;
        }
    }
    fclose(file);
    return arr[1024];
}