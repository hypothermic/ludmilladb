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

#include "router.h"

#include "all/sqlite.h"

static Router *router_new(const char* path)
{
    Router *rtr = (Router*)malloc(sizeof(Router));
    rtr->path = path;
    return rtr;
}

Router *router_new_sqlite(const char* path)
{
    Router* rtr = router_new(path);
    rtr->prov = SQLITE;
    return rtr;
}

Router *router_new_detect(const char* path)
{
    // TODO: Detect which database it is (example: MSAccess DB)
    // and return new router with correct provider.
    // Until ^^ is done, this returns sqlite provider.
    /*
    Router* rtr = router_new(path);
    return rtr;
    */
    return router_new_sqlite(path);
}

void router_free(Router *rtr)
{
    free(rtr);
}

void router_init(Router *rtr)
{
    switch (*rtr->prov)
    {
        case SQLITE:
            db_sqlite_init(rtr); break;

        // more once mysql gets implemented
    }
}