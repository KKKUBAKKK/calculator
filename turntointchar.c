//
// Created by Jakub Kindracki on 07/02/2023.
//

#include "turntointchar.h"
#include <stdio.h>
#include <stdlib.h>

// turn_to_int function
int turn_to_int(char in)
{
    if (in >= 0 && in <= 9)
    {
        atoi(&in);
        return in;
    }

    else if (in >= '0' && in <= '9')
    {
        atoi(&in);
        return in - 48;
    }

    else if (in == 'A' || in == 'a')
    {
        return 10;
    }

    else if (in == 'B' || in == 'b')
    {
        return 11;
    }

    else if (in == 'C' || in == 'c')
    {
        return 12;
    }

    else if (in == 'D' || in == 'd')
    {
        return 13;
    }

    else if (in == 'E' || in == 'e')
    {
        return 14;
    }

    else if (in == 'F' || in == 'f')
    {
        return 15;
    }

    else
    {
        fprintf(stderr, "ERROR: turn_to_int invalid input\n");
        exit(9);
    }
}

// turn_to_char function
char turn_to_char (int in)
{
    if (in >= 0 && in <= 9)
    {
        in = in + '0';
        return in;
    }

    else if (in == 10)
    {
        return 'A';
    }

    else if (in == 11)
    {
        return 'B';
    }

    else if (in == 12)
    {
        return 'C';
    }

    else if (in == 13)
    {
        return 'D';
    }

    else if (in == 14)
    {
        return 'E';
    }

    else if (in == 15)
    {
        return 'F';
    }

    else
    {
        fprintf(stderr, "ERROR: turn_to_char invalid input\n");
        exit(10);
    }
}