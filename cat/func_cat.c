/******************************************************************************
 *Name: func_cat.c
 *@brief: Personal implementation of cat command using C APIs from Linux.
 *This function is designed to be implemented with a main source file for
 *the minibusybox implementation.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "cat.h"

#define MAXBUFFSIZE 100

int func_cat(int num_arg, char *argument)
{
    //Creates a file object and tries to open the file specified in arg_v[>
    int file = open(argument, O_RDONLY);
    if (file == -1)
    {
        //If fails error message is returned
        perror("Error opening file: ");
        return 5;
    }
    //Prepares buffer to save data inside file
    char buff_file[MAXBUFFSIZE] = "\0";
    //Reads file as long as EOF has not been found
    while ((read(file, (char *)buff_file, MAXBUFFSIZE)) != 0)
    {
        printf("%s", buff_file);
        //Clears all data previously saved
        for (int i = 0; *(buff_file + i) != '\0'; i++)
        {
                *(buff_file + i) = '\0';
        }
    }
    //Closes file
    if (close(file) == -1)
    {
        perror("Error closing file: ");
        return 1;
    }

    return 0;
}

/*********************************END OF FILE*********************************/
