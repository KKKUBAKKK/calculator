#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "readinfile.h"
#include "convert.h"

#define MAX 41
#define SYS 3
#define DECIMAL 10

int main(int argc, const char *argv[])
{
    // read_file variables
    char out_file[MAX];
    int file_length;
    char empty_char[MAX] = "0";
    char line[MAX + 2] = "0";
    char operation[SYS] = "0";
    char system[SYS] = "0";
    char argument1[MAX] = "0";
    char argument2[MAX] = "0";
    int larg1;
    int larg2;
    int system_length;
    int sys;

    // adding variables
    char result[MAX] = "0";
    int result_length = 0;
    int i;

    // convert variables
    int op = 0;
    int operation_length = 0;

    // time variables
    clock_t start, end;
    double cpu_time_used;

    // Checking if there is enough arguments
    if (argc != 2)
    {
        fprintf(stderr, "ERROR: Usage: ./kj_count file_in.txt\n");
        exit(1);
    }

    strcpy(out_file, argv[1]);
    file_length = (int) strlen(argv[1]);

    out_file[file_length - 6] = 'o';
    out_file[file_length - 5] = 'u';
    out_file[file_length - 4] = 't';
    out_file[file_length - 3] = '.';
    out_file[file_length - 2] = 't';
    out_file[file_length - 1] = 'x';
    out_file[file_length] = 't';
    out_file[file_length + 1] = '\0';

    // Opening IN and OUT files
    FILE *IN = fopen(argv[1], "r");
    FILE *OUT = fopen(out_file, "w");

    fgets(line, MAX + 2, IN);

    // loop to run a function for every input
    while ((line[0] > '0' && line[0] < '9') || line[0] == '+' || line[0] == '*' || line[0] == '^' || line[0] == '/' || line[0] == '%')
    {
        putc('\n', OUT);
        fputs(line, OUT);

        // Start counting time for operation
        start = clock();

        // Executing read_op_sys function
        read_op_sys(IN, OUT, operation, system, line);

        // Executing read_argument functions
        larg1 = read_argument(IN, OUT, argument1);

        larg2 = read_argument(IN, OUT, argument2);

        fgets(line, MAX + 2, IN);
        fgets(line, MAX + 2, IN);

        // Creating a system variable of type int
        sys = turn_to_int(system[0]);
        system_length = 1;
        if (system[1] != '\0')
        {
            sys = sys * 10 + turn_to_int(system[1]);
            system_length = 2;
        }

        // Creating an operation variable of type int
        if (operation[0] >= '0' && operation[0] <= '9')
        {
            if (operation[1] != '\0')
            {
                operation_length = 2;
                op = turn_to_int(operation[0]) * 10 + turn_to_int(operation[1]);
            }
            else
            {
                operation_length = 1;
                op = turn_to_int(operation[0]);
            }
        }

        // Executing adding function
        if (*operation == '+')
        {
            if (larg1 >= larg2)
            {
                result_length = adding(result, argument1, argument2, larg1, larg2, sys);
            }
            else
            {
                result_length = adding(result, argument2, argument1, larg2, larg1, sys);
            }

            // Writing sum into the OUT file
            for (i = 0; result_length - i > 0; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

            // Execute multiplication function
        else if (*operation == '*')
        {
            result_length = multiplication(result, argument1, argument2, larg1, larg2, sys);

            // Writing sum into the OUT file
            for (i = 0; result_length - i > 0; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

            // Execute power function
        else if (*operation == '^')
        {
            result_length = power(result, argument2, argument1, result_length, larg2, larg1, sys);

            for (i = 0; result_length - i > 0; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

            // Execute division function
        else if (*operation == '/')
        {
            result_length = division(result, argument1, argument2, larg1, larg2, sys);

            for (i = 0; i < result_length; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

            // Execute modulo function
        else if (*operation == '%')
        {
            result_length = modulo(result, argument1, argument2, larg1, larg2, sys);

            for (i = 0; i < result_length; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

            // Execute convert function
        else if (*operation >= '1' && *operation <= '9')
        {
            result_length = convert(result, argument1, operation, system, system_length, larg1, operation_length, op, sys);

            for (i = 0; i < result_length; i++)
                putc(result[i], OUT);

            putc('\n', OUT);
        }

        // Time counting end
        end = clock();

        // Turn every variable back to 0
        // read_file variables
        strcpy(line, empty_char);
        strcpy(operation, empty_char);
        strcpy(system, empty_char);
        strcpy(argument1, empty_char);
        strcpy(argument2, empty_char);

        // adding variables
        strcpy(result, empty_char);
        result_length = 0;

        // convert variables
        op = 0;
        operation_length = 0;

        // Calculate and print out time
        cpu_time_used = ((double) (end - start) / CLOCKS_PER_SEC);
        printf("Time: %f\n", cpu_time_used);

        fgets(line, MAX + 2, IN);
    }

    // Returning '0' from main
    return 0;
}
