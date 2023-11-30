//
// Created by Jakub Kindracki on 07/02/2023.
//
#define MAX 41
#define SYS 3
#define DECIMAL 10

#include "convert.h"
#include <stdio.h>
#include <stdlib.h>

// convert function
int convert(char *result, char *argument, char *system, char *operation, int operation_length, int larg, int system_length, int sys, int op)
{
    char multiplicator[MAX] = "0";
    int multip_length = 0;
    int i = 0;
    int j = 0;
    char power_char[SYS] = "0";
    int power_length = 0;
    char ctemp[MAX] = "0";
    int ctemp_length = 0;
    char dec_argument[SYS] = "0";
    int dec_arg_length = 0;
    char part[MAX] = "0";
    int part_length = 0;
    char temp[MAX] = "0";
    int temp_length = 0;

    if (sys != DECIMAL)
    {
        for (i = 0; larg - i > 0; i++)
        {
            power_char[0] = turn_to_char(i % DECIMAL);
            power_length = 1;
            if (i >= DECIMAL)
            {
                power_char[1] = turn_to_char((i - i % DECIMAL) / DECIMAL);
                power_length = 2;
            }
            ctemp_length = power(ctemp, system, power_char, ctemp_length, system_length, power_length, DECIMAL);

            dec_argument[0] = turn_to_char(turn_to_int(argument[larg - 1 - i]) % DECIMAL);
            dec_arg_length = 1;
            if (turn_to_int(argument[larg - 1 - i]) >= DECIMAL)
            {
                dec_argument[0] = turn_to_char((turn_to_int(argument[larg - 1 - i]) - turn_to_int(argument[larg - 1 - i]) % DECIMAL) / DECIMAL);
                dec_argument[1] = turn_to_char(turn_to_int(argument[larg - 1 - i]) % DECIMAL);
                dec_arg_length = 2;
            }
            part_length = multiplication(part, dec_argument, ctemp, dec_arg_length, ctemp_length, DECIMAL);

            if (temp_length >= part_length)
            {
                temp_length = adding(temp, temp, part, temp_length, part_length, DECIMAL);
            }
            else
            {
                temp_length = adding(temp, part, temp, part_length, temp_length, DECIMAL);
            }
        }
    }
    else
    {
        for (i = 0; i < larg; i++)
        {
            temp[i] = argument[i];
        }
        temp_length = larg;
    }

    for (i = 0; i < MAX; i++)
    {
        ctemp[i] = '\0';
        part[i] = '\0';
    }
    ctemp_length = 0;
    part_length = 0;
    i = 0;

    if (op != DECIMAL)
    {
        multiplicator[0] = '1';
        multip_length = 1;
        while (compare("1", multiplicator, 1, multip_length) <=0)
        {
            if (i > MAX - 2)
            {
                fprintf(stderr, "ERROR: result > %i", MAX - 1);
                exit(14);
            }

            for (j = 0; j < SYS; j++)
                dec_argument[j] = '\0';

            for (j = 0; j < multip_length; j++)
                multiplicator[j] = '\0';
            multiplicator[0] = '0';
            multip_length = 1;

            multip_length = division(multiplicator, temp, operation, temp_length, operation_length, DECIMAL);
            dec_arg_length = modulo(dec_argument, temp, operation, temp_length, operation_length, DECIMAL);

            if (compare("0", multiplicator, 1, multip_length) < 0)
            {
                for (j = 0; j < temp_length; j++)
                    temp[j] = '\0';
                temp_length = 0;

                part_length = multiplication(part, multiplicator, operation, multip_length, operation_length, DECIMAL);
                temp_length = division(temp, part, operation, part_length, operation_length, DECIMAL);
            }

            j = turn_to_int(dec_argument[0]);
            if (dec_arg_length > 1)
                j = j * DECIMAL + turn_to_int(dec_argument[1]);

            ctemp[i] = turn_to_char(j);
            ctemp_length++;
            i++;
        }

        for (i = 0; i < ctemp_length; i++)
        {
            result[i] = ctemp[ctemp_length - 1 - i];
        }
        return ctemp_length;
    }
    else
    {
        for (i = 0; i < temp_length; i++)
        {
            result[i] = temp[i];
        }
        return temp_length;
    }
}