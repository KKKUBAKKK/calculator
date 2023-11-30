//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "mutliplication.h"

// multiplication function
int multiplication(char *result, char *argument1, char *argument2, int larg1, int larg2, int sys)
{
    int i = 0;
    int j = 1;
    int k = 0;
    int l = 0;
    int result_length = 0;
    int temp_length = 0;
    char temp[MAX] = "0";
    char tempr[MAX] = "0";
    for (j = 0; MAX - j > 0; j++)
    {
        result[j] = '\0';
    }

    while (larg1 > 0)
    {
        if (turn_to_int(argument1[larg1 - 1]) != 0)
        {
            for (j = 0; MAX - j > 0; j++)
            {
                temp[j] = '\0';
                tempr[j] = '\0';
            }
            i = 0;
            j = 0;

            while (larg2 - j > 0)
            {
                i = turn_to_int(argument1[larg1 - 1]) * turn_to_int(argument2[larg2 - 1 - j]) + turn_to_int(temp[j + k]);

                for (l = 0; l < k; l++)
                {
                    temp[l] = '0';
                }

                temp[j + k] = turn_to_char(i % sys);

                if (i >= sys)
                {
                    temp[j + 1 + k] = turn_to_char((i - i % sys) / sys);
                }

                j++;
            }

            if (temp[j + k] != '\0')
                temp_length = j + 1 + k;
            else
                temp_length = j + k;

            for (j = 0; temp_length - j > 0; j++)
                tempr[j] = temp[temp_length - 1 - j];

            if (result_length >= temp_length)
            {
                result_length = adding(result, result, tempr, result_length, temp_length, sys);
            }
            else
            {
                result_length = adding(result, tempr, result, temp_length, result_length, sys);
            }

        }
        larg1--;
        k++;
    }
    return result_length;
}