//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41
#define SYS 3

#include "readinfile.h"
#include <stdlib.h>

// read_op_sys function
void read_op_sys(FILE *IN, FILE *OUT, char operation[SYS], char system[SYS], char *line)
{
    int i = 0, j = 0;

    while (line[i] != ' ')
    {
        operation[j] = line[i];
        i++;
        j++;
    }

    i++;
    j = 0;
    while (line[i] != '\n' && line[i] != '\0' && line[i] != EOF)
    {
        system[j] = line[i];
        i++;
        j++;
    }

    fgets(line, MAX + 2, IN);
    fputs(line, OUT);
}

// read_argument function
int read_argument(FILE *IN, FILE *OUT, char argument[MAX])
{
    char line[MAX + 2];
    int i = 0;


    fgets(line, MAX + 2, IN);
    if (line[i] == '\n')
    {
        fgets(line, MAX + 2, IN);
        return 0;
    }
    fputs(line, OUT);

    while (line[i] != '\n' && line[i] != '\0' && line[i] != EOF)
    {
        if (i > MAX - 2)
        {
            fprintf(stderr, "ERROR: argument longer than %i\n", MAX - 1);
            exit(4);
        }

        argument[i] = line[i];
        i++;
    }

    fgets(line, MAX + 2, IN);
    fputs(line, OUT);

    return i;
}