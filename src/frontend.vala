using Gtk;

[GtkTemplate (ui = "/nl/hypothermic/ludmilladb/res/window.ui")]
public class LuDB.Window : Gtk.Window {

	[GtkChild]
	private TreeView list_treeview;

	construct {

	}

	[GtkCallback]
    private void window_destroyed() {
		print("The window got destroyed!\n");
		Gtk.main_quit();
    }
}
