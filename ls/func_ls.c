/******************************************************************************
 *Name: func_ls.c
 *@brief: Personal implementation of ls command function using C APIs
 *from Linux. This function is designed to be used in conjunction with
 *minibusybox main program.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "ls.h"

int func_ls(int num_arg, char *argument)
{
    char *directory = NULL;
    struct dirent *dir;
    //Checks if second argument is empty to print files in PWD
    if (argument == NULL)
    {
        directory = (char *)get_current_dir_name();
    }
    //If it is not empty saves the directory entered inside arg_v[1]
    else
    {
        directory = (char *)argument;
    }
    //Opens a directory stream defined by char *directory
    DIR *dr = opendir(directory);
    //Checks if was successfull
    if (dr == NULL)
    {
        perror("Error opening directory: ");
        return 4;
    }
    //Prints all the files names inside the directory specified
    while ((dir = readdir(dr)) != NULL)
    {
        printf("%s\t", dir->d_name);
    }
    printf("\n");
    //Close the dir stream
    closedir(dr);
    return 0;
}

/*********************************END OF FILE*********************************/

