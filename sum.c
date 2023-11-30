//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "sum.h"
#include <stdlib.h>
#include <stdio.h>


int adding(char *sum, char *argument1, char *argument2, int larg1, int larg2, int system)
{
    long temp;
    int i = 0, sum_length, j;
    char bsum[MAX] = "0";

    while (larg2 > 0)
    {
        if (i > MAX - 2)
        {
            fprintf(stderr, "ERROR: sum longer than %i\n", MAX - 1);
            exit(5);
        }

        if (larg1 == 0)
        {
            for (j = 0; j < larg2; j++)
            {
                sum[j] = argument2[j];
            }
            return j;
        }

        temp = turn_to_int(argument1[larg1 - 1]) + turn_to_int(argument2[larg2 - 1]) + turn_to_int(bsum[i]);

        bsum[i] = turn_to_char((int) temp % system);

        if (temp >= system)
            bsum[i + 1] = turn_to_char((int) (temp - temp % system) / system);

        larg1--;
        larg2--;
        i++;
    }

    while (larg1 > 0)
    {
        if (i > MAX - 2)
        {
            fprintf(stderr, "ERROR: sum longer than %i\n", MAX - 1);
            exit(7);
        }

        temp = turn_to_int(argument1[larg1 - 1]) + turn_to_int(bsum[i]);

        bsum[i] = turn_to_char((int) temp % system);

        if (temp >= system)
        {
            if (i > MAX - 2)
            {
                fprintf(stderr, "ERROR: sum longer than %i\n", MAX - 1);
                exit(8);
            }

            bsum[i + 1] = turn_to_char((int) (temp - temp % system) / system);
        }

        larg1--;
        i++;
    }

    if (bsum[i] != '\0')
        sum_length = i + 1;
    else
        sum_length = i;

    for (i = 0; sum_length - i > 0; i++)
    {
        sum[i] = bsum[sum_length - 1 - i];
    }

    return sum_length;
}