/******************************************************************************
 *Name: func_uptime.c
 *@brief: Personal implementation of uptime command using C APIs from Linux.
 *This function is designed to be implemented with a main source file for
 *minibusybox implementation.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/sysinfo.h>
#include "uptime.h"

int func_uptime(int num_arg)
{
    struct sysinfo systime;
    if (sysinfo(&systime) == -1)
    {
        perror("Error reading system info: ");
        return 6;
    }
    //Extracts the days that system has been running
    unsigned long days = systime.uptime / 86400;
    //Extracts the hours that system has been running
    unsigned char hours = (systime.uptime % 86400) / 3600;
    //Extracts the minutes that system has been running
    unsigned char minutes = ((systime.uptime % 86400) % 3600) / 60;
    //Extracts the seconds that system has been running
    unsigned char seconds = (((systime.uptime) % 86400) % 3600) % 60;
    printf("Up %lu days, %hu hours, %hu minutes and %hu seconds\n", days, hours, minutes, seconds);
    printf("Load average: %1.2f, %1.2f, %1.2f\n", systime.loads[0]/65536.0f, systime.loads[1]/65536.0f, systime.loads[2]/65536.0f);
    return 0;
}

/*********************************END OF FILE*********************************/
