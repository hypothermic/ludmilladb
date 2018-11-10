/**             | |         | |         (_| | |             | | |                **\
 *              | |_   _  __| |_ __ ___  _| | | __ _      __| | |__               *
 *              | | | | |/ _` | '_ ` _ \| | | |/ _` |    / _` | '_ \              *
 *              | | |_| | (_| | | | | | | | | | (_| |   | (_| | |_) |             *
\**             |_|\__,_|\__,_|_| |_| |_|_|_|_|\__,_|    \__,_|_.__/             **/

/**                                                                              **\
 *                  This file belongs to the Ludmilla project.                    *
 *                     It is licensed under the MIT License.                      *
 *                                                                                *
 *              -=  Filename: router.h                            =-              *
 *              -=  Authors: hypothermic <admin@hypothermic.nl>   =-              *
 *              -=  Since version: v1.000 (created: 05/11/2018)   =-              *
\**                                                                              **/

#ifndef ROUTER_H_
#define ROUTER_H_

#include <stdlib.h>

#include "provider.h"

typedef struct _Router
{
    Provider *prov;   // set at construction
    const char* path; // database path
} Router;

Router *router_new_sqlite(const char* path);

Router *router_new_detect(const char* path);

void router_free(Router *rtr);

#endif // ROUTER_H_