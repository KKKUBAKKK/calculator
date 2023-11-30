//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "power.h"
#include <math.h>

// power function
int power(char *result, char *argument, char *pow_number,int result_length, int larg, int power_length, int sys)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int power_number = 0;
    char tempr[MAX] = "0";

    for(i = 0; power_length - i > 0; i++)
    {
        temp = (int) pow(sys, i) * turn_to_int(pow_number[power_length - 1 - i]);

        power_number = power_number + temp;
    }

    if (power_number == 0)
    {
        *result = '1';
        result_length = 1;
    }
    else
    {
        for (i = 0; larg - i > 0; i++)
            result[i] = argument[i];
        result_length = larg;
        if (power_number != 1)
        {
            for (i = 1; i < power_number; i++)
            {
                for (j = 0; j < result_length; j++)
                    tempr[j] = result[j];

                result_length = multiplication(result, tempr, argument, result_length, larg, sys);
            }
        }
    }
    return result_length;
}