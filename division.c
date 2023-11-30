//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41

#include "division.h"
#include <string.h>

// division function
int division(char *result, char *arg1, char *argument2, int larg1, int larg2, int sys)
{
    int i = 0, j = 0, k = 0, l = 0, tlength = 0, tresult_length = 0, bresult_length = 0, result_length = 0;
    char temp[MAX] = "0";
    char tresult[MAX] = "0";
    char bresult[MAX] = "0";
    char argument1[MAX] = "0";
    strcpy(argument1, arg1);

    if (compare(argument1, argument2, larg1, larg2) < 0)
    {
        result = "0";
        return 1;
    }
    else if (compare(argument1, argument2, larg1, larg2) == 0)
    {
        result[0] = '1';
        return 1;
    }
    else
    {
        for (i = 0; larg1 > i; i++)
        {
            j = 0;
            while (argument1[j] == '0')
            {
                j++;
            }

            tlength = 0;
            for (k = 0; j <= i; j++, k++)
            {
                temp[k] = argument1[j];
                tlength++;
            }

            j = 0;
            if (compare(temp, argument2, tlength, larg2) >= 0)
            {
                tresult_length = subtract(tresult, temp, argument2, tlength, larg2, sys);
                j = 1;
                while (compare(tresult, argument2, tresult_length, larg2) >= 0)
                {
                    strcpy(temp, tresult);
                    tlength = tresult_length;
                    for (k = 0; k < tresult_length; k++)
                        tresult[k] = '\0';
                    tresult_length = subtract(tresult, temp, argument2, tlength, larg2, sys);
                    j++;
                }
                strcpy(temp, tresult);
                tlength = tresult_length;

                if (tlength < i + 1)
                {
                    for (k = 0; k < i + 1 - tlength; k++)
                    {
                        argument1[k] = '0';
                    }
                    if (compare(temp, "0", tlength, 1) >= 0)
                    {
                        for (l = 0; l < tlength; k++, l++)
                        {
                            argument1[k] = temp[l];
                        }
                    }
                }
                else
                {
                    for (k = 0; k < tlength; k++)
                    {
                        argument1[k] = temp[k];
                    }
                }
                bresult[i] = turn_to_char(j);
            }
            else
            {
                bresult[i] = '0';
            }
            bresult_length++;
        }

        i = 0;
        j = 0;
        while (bresult[i] == '0')
        {
            i++;
        }

        result_length = bresult_length - i;
        for ( ; i < bresult_length; i++)
        {
            result[j] = bresult[i];
            j++;
        }

        return result_length;
    }
}