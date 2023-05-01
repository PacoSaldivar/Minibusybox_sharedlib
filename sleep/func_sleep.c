/******************************************************************************
 *Name: func_sleep.c
 *@brief: Personal implementation of sleep function to be used in conjunction
 *with other similar features to build a personal implementation of minibusybox.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 26/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sleep.h"

int func_sleep(int num_arg, char *argument)
{
    char *ptr_char = argument;
    //And the second argument must be a digit
    for (int i = 0; i < strlen(ptr_char); i++)
    {
        if (!isdigit(ptr_char[i]))
        {
            puts("Error, the sleep argument is not valid");
            return 2;
        }
    }
    unsigned int sleep_seconds = atoi(argument);
    sleep(sleep_seconds);
    return 0;
}

/*********************************END OF FILE*********************************/
