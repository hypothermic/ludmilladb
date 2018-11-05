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
#include <stdlib.h>

#include "ludmilla.h"

#include "deployer/deployer.h"
#include "w_chooser/w_chooser.h"

static void activate(GtkApplication *app, gpointer data);
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

GtkApplication *app;
GObject *window;
int w_stage = PRE;

int main(int argc, char **argv)
{
	printf("\n--- Ludmilla Database Software ---\n");

    printf("Checking resources...");
    int deploy_result = deployer_check_resources();
    if (deploy_result != 0)
    {
        printf(" error code %d", deploy_result);
        return 1;
    };
    printf(" done.\n");

    int app_status;

    app = gtk_application_new("nl.hypothermic.ludmilla", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    app_status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return app_status;
}

static void activate(GtkApplication *app, gpointer data)
{
    GtkBuilder *builder = gtk_builder_new();
    GtkCssProvider *provider = gtk_css_provider_new();

    char window_ui_path[128];
    strcpy(window_ui_path, getenv("HOME"));
    strcat(window_ui_path, "/.ludmilladb/res/window.ui");
    gtk_builder_add_from_file(builder, window_ui_path, NULL);
    window = gtk_builder_get_object(builder, "w_chooser");
    g_signal_connect(G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);
    gtk_application_add_window(app, GTK_WINDOW(window));
    gtk_builder_connect_signals(builder, NULL);
    gtk_css_provider_load_from_path(provider, strcat(getenv("HOME"), "/.ludmilladb/res/window.css"), NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    w_chooser_bind(builder);
}

gboolean
on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    switch (event->keyval) {
        case GDK_KEY_F:
        case GDK_KEY_f:
            if (w_stage == 1) {
                cb_w_chooser_file();
                break;
            }
        case GDK_KEY_N:
        case GDK_KEY_n:
            if (w_stage == 1) {
                cb_w_chooser_new();
                break;
            }
    default:
        return FALSE; 
    }
    return FALSE; 
}