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

#include "w_chooser.h"

#include "../w_session/w_session.h"
#include "../provider/router.h"

extern GtkApplication *app;
extern GObject *window;
extern int w_stage;

static GtkBuilder *builder_local;

void w_chooser_bind(GtkBuilder *builder)
{
    w_stage = W_CHOOSER;
    builder_local = builder;

    g_signal_connect(gtk_builder_get_object(builder, "c_ls_new_w"), "button_press_event", cb_w_chooser_new, NULL);
    g_signal_connect(gtk_builder_get_object(builder, "c_ls_file_w"), "button_press_event", cb_w_chooser_file, NULL);
    g_signal_connect(gtk_builder_get_object(builder, "m_f_q"), "button_press_event", cb_w_chooser_m_quit, NULL);
}

void cb_w_chooser_new()
{
    printf("TO-DO: NEW\n");
}

void cb_w_chooser_file()
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;
    char *filename;
    boolean succeeded = false;

    dialog = gtk_file_chooser_dialog_new("Load Database",
                                         window,
                                         action,
                                         ("_Cancel"),
                                         GTK_RESPONSE_CANCEL,
                                         ("_Load"),
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        succeeded = true;
    }

    gtk_widget_destroy (dialog);

    if (succeeded) {
        cb_w_chooser_finish(router_new_detect(filename));
    }
}

void cb_w_chooser_finish(Router rtr)
{
    //gtk_widget_destroy(window);
    gtk_widget_hide(window);
    w_session_bind(builder_local, rtr);
}

void cb_w_chooser_m_quit()
{
    g_application_quit(G_APPLICATION(app));
}