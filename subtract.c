//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "subtract.h"
#include <stdio.h>
#include <stdlib.h>

// subtract function
int subtract(char *result, char *argument1, char *argument2, int larg1, int larg2, int sys)
{
    int i = 0, j = 0;
    int temp = 0;
    int minus = 0;
    int result_length = 0;
    char result_temp[MAX] = "0";

    if (compare(argument1, argument2, larg1, larg2) < 0)
    {
        fprintf(stderr, "ERROR: subtract function: result < 0\n");
        exit(11);
    }
    else if (compare(argument1, argument2, larg1, larg2) == 0)
    {
        result[0] = '0';
        return 1;
    }

    for (i = 0; larg2 - i > 0; i++)
    {
        temp = turn_to_int(argument1[larg1 - 1 - i]);
        minus = turn_to_int(argument2[larg2 - 1 - i]);

        if (temp >= minus)
        {
            result_temp[larg1 - 1 - i] = turn_to_char(temp - minus);
        }
        else
        {
            if (turn_to_int(argument1[larg1 - 2 - i]) >= 1)
            {
                temp += sys;
                argument1[larg1 - 2 - i] = turn_to_char(turn_to_int(argument1[larg1 - 2 - i]) - 1);
                result_temp[larg1 - 1 - i] = turn_to_char(temp - minus);
            }
            else
            {
                for (j = i; j < larg1; j++)
                {
                    if (turn_to_int(argument1[larg1 - 2 - j]) >= 1)
                        break;
                }
                argument1[larg1 - 2 - j] = turn_to_char(turn_to_int(argument1[larg1 - 2 - j]) - 1);
                for (j -= 1 ; j + 1 > 0; j--)
                {
                    argument1[larg1 - 2 - j] = turn_to_char(turn_to_int(argument1[larg1 - 2 - j]) + sys - 1);
                }
                temp += sys;
                result_temp[larg1 - 1 - i] = turn_to_char(temp - minus);
            }
        }
    }

    for ( ; larg1 - i > 0; i++)
    {
        result_temp[larg1 - 1 - i] = argument1[larg1 - 1 - i];
    }

    for (j = 0, i = 0; larg1 > i; i++)
    {
        if (result_temp[i] != '0')
        {
            result[j] = result_temp[i];
            j++;
        }
    }

    i = 0;
    while (result_temp[i] == '0' && i < larg1)
    {
        i++;
    }

    for (j = 0; i < larg1; i++, j++)
    {
        result[j] = result_temp[i];
    }

    result_length = j;

    return result_length;
}