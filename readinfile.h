//
// Created by Jakub Kindracki on 07/02/2023.
//

#ifndef KALKULATOR_READINFILE_H
#define KALKULATOR_READINFILE_H

#include <stdio.h>

void read_op_sys(FILE *IN, FILE *OUT, char operation[], char system[], char *line);
int read_argument(FILE *IN, FILE *OUT, char argument[]);

#endif //KALKULATOR_READINFILE_H
