/******************************************************************************
 *Name: func_uname.c
 *@brief: Personal implementation of uname command using C APIs from Linux.
 *This function is designed to be implemented with a main function of
 *minibusybox implementation.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/utsname.h>
#include "uname.h"

int func_uname(int num_arg)
{
    //Obtains system information with utsname struct
    struct utsname os_info;
    if (uname(&os_info) == 0)
    {
        printf("Kernel name: %s\n", os_info.sysname);
        printf("Kernel release: %s\n", os_info.release);
        printf("Kernel version: %s\n", os_info.version);
        printf("Processor: %s\n", os_info.machine);
        return 0;
    }
    else
    {
        perror("Error accessing OS info: ");
        return 3;
    }
}

/*********************************END OF FILE*********************************/
