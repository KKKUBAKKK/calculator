//
// Created by Jakub Kindracki on 07/02/2023.
//

#include "compare.h"
#include <string.h>

int compare(char *argument1, char *argument2, int larg1, int larg2)
{
    int i = 0;

    if (larg1 == larg2)
    {
        i = strcmp(argument1, argument2);
        return i;
    }
    else
    {
        return larg1 - larg2;
    }
}