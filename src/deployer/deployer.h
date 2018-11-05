/**             | |         | |         (_| | |             | | |                **\
 *              | |_   _  __| |_ __ ___  _| | | __ _      __| | |__               *
 *              | | | | |/ _` | '_ ` _ \| | | |/ _` |    / _` | '_ \              *
 *              | | |_| | (_| | | | | | | | | | (_| |   | (_| | |_) |             *
\**             |_|\__,_|\__,_|_| |_| |_|_|_|_|\__,_|    \__,_|_.__/             **/

/**                                                                              **\
 *                  This file belongs to the Ludmilla project.                    *
 *                     It is licensed under the MIT License.                      *
 *                                                                                *
 *              -=  Filename: deployer.h                          =-              *
 *              -=  Authors: hypothermic <admin@hypothermic.nl>   =-              *
 *              -=  Since version: v1.000 (created: 05/11/2018)   =-              *
\**                                                                              **/

#ifndef DEPLOYER_H_
#define DEPLOYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#pragma GCC diagnostic ignored "-Wformat-security"

static int avio_exists(const char *fname);
static void avio_write(const char *fname, char *text);

int avio_exists(const char *fname)
{
    if (access(fname, F_OK) != -1) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void avio_write(const char *fname, char *text)
{
    FILE *ptr; 

	ptr = fopen(fname, "w"); 
 
	fprintf(ptr, text);
	
	fclose(ptr); 
}

int deployer_check_resources();

char *get_window_ui();
char *get_window_css();
char *get_icoadd();
char *get_icofile();

#endif // DEPLOYER_H_