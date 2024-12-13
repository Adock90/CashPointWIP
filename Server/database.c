#ifndef _c_
#define _c_
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char *DataStr;
typedef char DataArray[];
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

DataStr *ReadDataCSV(DataStr filename, struct CsvPoints SetWhere, DataStr RowName, DataStr ColoumnName)
{
    DataBool ColoumnCheck;
    DataBool RowCheck;
    DataBool ColNumCheck;
    DataBool RowNumCheck;

    DataStr ReturnArray = (char *)malloc(1024 * sizeof(char));

    if (ReturnArray == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(-1);
    }
    DataStr result = NULL;

    if (RowName == NULL || RowName == "")
    {
        RowCheck = false;
    }
    else if (ColoumnName == NULL || ColoumnName == "")
    {
        ColoumnCheck == false;
    }
    else
    {
        RowCheck = true;
        ColoumnCheck = true;
    }
    if (SetWhere.coloumns == NULL || SetWhere.coloumns == -1)
    {
        ColNumCheck = false;
    }
    else if (SetWhere.rows == NULL || SetWhere.coloumns == -1)
    {
        RowNumCheck = false;
    }
    else
    {
        RowNumCheck = true;
        ColNumCheck = true;
    }

    FILE *file;

    file = fopen(filename, "r");

    if (filename == NULL || !file)
    {
        printf("Target Not Found\n");
        exit(0);
    }
    else
    {
        char buffer[1024];

        DataInt row = 0;
        DataInt coloumn = 0;
        DataInt Checker = 0;
        struct CsvPoints CheckPoints = {0, 0};
        while (fgets(buffer, 1024, file))
        {
            row++;
            coloumn = 0;
            DataStr value = strtok(buffer, ",");
            if (RowCheck && RowName == value)
            {
                CheckPoints.rows = row;
            }
            if (row == SetWhere.rows || value == RowName)
            {
                bool breakable = false;
                while (value || !breakable)
                {
                    value = strtok(NULL, ",");
                    if (value == ColoumnName && RowCheck)
                    {
                        result = value;
                        breakable = true;
                        break;
                    }
                    else if (RowNumCheck && SetWhere.rows == row || SetWhere.coloumns == coloumn && ColNumCheck)
                    {
                        result = value;
                    }
                    else
                    {
                        continue;
                    }
                    coloumn++;
                }
            }
        }
    }

    if (ReturnArray != NULL)
    {
        result = ReturnArray;
    }
    return (char **)result;
}