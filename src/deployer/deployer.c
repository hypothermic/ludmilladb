/**             | |         | |         (_| | |             | | |                **\
 *              | |_   _  __| |_ __ ___  _| | | __ _      __| | |__               *
 *              | | | | |/ _` | '_ ` _ \| | | |/ _` |    / _` | '_ \              *
 *              | | |_| | (_| | | | | | | | | | (_| |   | (_| | |_) |             *
\**             |_|\__,_|\__,_|_| |_| |_|_|_|_|\__,_|    \__,_|_.__/             **/

/**                                                                              **\
 *                  This file belongs to the Ludmilla project.                    *
 *                     It is licensed under the MIT License.                      *
 *                                                                                *
 *              -=  Filename: deployer.c                          =-              *
 *              -=  Authors: hypothermic <admin@hypothermic.nl>   =-              *
 *              -=  Since version: v1.000 (created: 05/11/2018)   =-              *
\**                                                                              **/

#include <sys/stat.h>

#include "deployer.h"
#include "../../include/str_builder/str_builder.h"

int deployer_check_resources()
{
    char basedir[128];
    strcpy(basedir, getenv("HOME"));

    strcat(basedir, "/.ludmilladb/");
    if (!avio_exists(basedir))
    {
        int result = mkdir(basedir, ACCESSPERMS);
        if (result != 0) {
            return 2;
        }
    }

    char basedir2[128];
    strcpy(basedir2, basedir);

    char* resdir = strcat(basedir, "res/");
    if (!avio_exists(resdir))
    {
        int result = mkdir(resdir, ACCESSPERMS);
        if (result != 0) {
            return 2;
        }
    }

    strcpy(basedir, basedir2);

    char* icodir = strcat(basedir, "res/ico/");
    if (!avio_exists(icodir))
    {
        int result = mkdir(icodir, ACCESSPERMS);
        if (result != 0) {
            return 2;
        }
    }

    strcpy(basedir, basedir2);

    char *windowuipath = strcat(basedir, "res/window.ui");
    if (!avio_exists(windowuipath))
    {
        avio_write(windowuipath, get_window_ui());
    }

    strcpy(basedir, basedir2);

    char *windowcsspath = strcat(basedir, "res/window.css");
    if (!avio_exists(windowcsspath))
    {
        avio_write(windowcsspath, get_window_css());
    }

    strcpy(basedir, basedir2);

    char *icoaddpath = strcat(basedir, "res/ico/add.svg");

    if (!avio_exists(icoaddpath))
    {
        avio_write(icoaddpath, get_icoadd());
    }

    strcpy(basedir, basedir2);

    char *icofilepath = strcat(basedir, "res/ico/file.svg");

    if (!avio_exists(icofilepath))
    {
        avio_write(icofilepath, get_icofile());
    }

    strcpy(basedir, basedir2);

    return 0;
}

char *get_window_ui()
{
    extern char _binary____res_window_ui_start;
    extern char _binary____res_window_ui_end;
    extern int _binary____res_window_ui_size;

    char *p = &_binary____res_window_ui_start;

    str_builder_t *sb;
    char *result;

    sb = str_builder_create();

    while (p != &_binary____res_window_ui_end)
    {
        str_builder_add_char(sb, *p++);
    }

    result = str_builder_dump(sb, NULL);

    str_builder_destroy(sb);

    return result;
}

char *get_window_css()
{
    extern char _binary____res_window_css_start;
    extern char _binary____res_window_css_end;
    extern int _binary____res_window_css_size;

    char *p = &_binary____res_window_css_start;

    str_builder_t *sb;
    char *result;

    sb = str_builder_create();

    while (p != &_binary____res_window_css_end)
    {
        str_builder_add_char(sb, *p++);
    }

    result = str_builder_dump(sb, NULL);

    str_builder_destroy(sb);

    return result;
}

char *get_icoadd()
{
    extern char _binary____res_ico_baseline_add_24px_svg_start;
    extern char _binary____res_ico_baseline_add_24px_svg_end;
    extern int _binary____res_ico_baseline_add_24px_svg_size;

    char *p = &_binary____res_ico_baseline_add_24px_svg_start;

    str_builder_t *sb;
    char *result;

    sb = str_builder_create();

    while (p != &_binary____res_ico_baseline_add_24px_svg_end)
    {
        str_builder_add_char(sb, *p++);
    }

    result = str_builder_dump(sb, NULL);

    str_builder_destroy(sb);

    return result;
}

char *get_icofile()
{
    extern char _binary____res_ico_baseline_insert_drive_file_24px_svg_start;
    extern char _binary____res_ico_baseline_insert_drive_file_24px_svg_end;
    extern int _binary____res_ico_baseline_insert_drive_file_24px_svg_size;

    char *p = &_binary____res_ico_baseline_insert_drive_file_24px_svg_start;

    str_builder_t *sb;
    char *result;

    sb = str_builder_create();

    while (p != &_binary____res_ico_baseline_insert_drive_file_24px_svg_end)
    {
        str_builder_add_char(sb, *p++);
    }

    result = str_builder_dump(sb, NULL);

    str_builder_destroy(sb);

    return result;
}