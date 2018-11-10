/**             | |         | |         (_| | |             | | |                **\
 *              | |_   _  __| |_ __ ___  _| | | __ _      __| | |__               *
 *              | | | | |/ _` | '_ ` _ \| | | |/ _` |    / _` | '_ \              *
 *              | | |_| | (_| | | | | | | | | | (_| |   | (_| | |_) |             *
\**             |_|\__,_|\__,_|_| |_| |_|_|_|_|\__,_|    \__,_|_.__/             **/

/**                                                                              **\
 *                  This file belongs to the Ludmilla project.                    *
 *                     It is licensed under the MIT License.                      *
 *                                                                                *
 *              -=  Filename: w_chooser.c                         =-              *
 *              -=  Authors: hypothermic <admin@hypothermic.nl>   =-              *
 *              -=  Since version: v1.000 (created: 05/11/2018)   =-              *
\**                                                                              **/

#include <gtk/gtk.h>

#include "../w_chooser/w_chooser.h"
#include "../provider/router.h"

void cb_w_session_m_quit();

extern GtkApplication *app;
extern GObject *window; // w_chooser window
static GObject *window_ses; // this window
extern int w_stage;

void w_session_bind(GtkBuilder *builder, Router rtr)
{
    window_ses = gtk_builder_get_object(builder, "w_session");

    g_signal_connect(window_ses, "destroy", cb_w_session_m_quit, NULL);

    gtk_widget_show(window_ses);
}

void cb_w_session_close()
{
    gtk_widget_destroy(window);
    // TODO: close db
}

void cb_w_session_m_quit()
{
    cb_w_session_close();
    g_application_quit(G_APPLICATION(app));
}