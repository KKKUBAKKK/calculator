//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "modulo.h"

// modulo function
int modulo(char *result, char *argument1, char *argument2, int larg1, int larg2, int sys)
{
    char rtemp[MAX] = "0";
    int rtemp_length = 0, result_length = 0;
    char temp[MAX] = "0";
    int temp_length = 0;

    rtemp_length = division(rtemp, argument1, argument2, larg1, larg2, sys);
    temp_length = multiplication( temp, rtemp, argument2, rtemp_length, larg2, sys);

    result_length = subtract(result, argument1, temp, larg1, temp_length, sys);

    return result_length;
}