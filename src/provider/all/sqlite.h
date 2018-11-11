/**             | |         | |         (_| | |             | | |                **\
 *              | |_   _  __| |_ __ ___  _| | | __ _      __| | |__               *
 *              | | | | |/ _` | '_ ` _ \| | | |/ _` |    / _` | '_ \              *
 *              | | |_| | (_| | | | | | | | | | (_| |   | (_| | |_) |             *
\**             |_|\__,_|\__,_|_| |_| |_|_|_|_|\__,_|    \__,_|_.__/             **/

/**                                                                              **\
 *                  This file belongs to the Ludmilla project.                    *
 *                     It is licensed under the MIT License.                      *
 *                                                                                *
 *              -=  Filename: ludmilla.c                          =-              *
 *              -=  Authors: hypothermic <admin@hypothermic.nl>   =-              *
 *              -=  Since version: v1.000 (created: 05/11/2018)   =-              *
\**                                                                              **/

#include <stdio.h>

#include <sqlite3.h>

#include "../router.h"

void *db_sqlite_init(Router *rtr)
{
    sqlite3 *db;

    sqlite3_open(rtr->path, &db);

    if (db == NULL)
	{
		printf("Error while opening db %s\n", rtr->path);
        return NULL;
    }
    else 
    {
        return db;
    }
}

void db_sqlite_query(Router *rtr)
{

}