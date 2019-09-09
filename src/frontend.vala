using GLib;

using Gtk;

[GtkTemplate (ui = "/nl/hypothermic/ludmilladb/res/window.ui")]
public class LuDB.Window : Gtk.Window {

	[GtkChild]
	private TreeView list_treeview;

	private List<Session> sessions = new List<Session>();

	construct {
		sessions.append(new LuDB.GBackend.Session());

		foreach (Session session in sessions) {
			session.initialize(".", "ludbx.db");
		}
	}

	[GtkCallback]
    private void window_destroyed() {
		print("The window got destroyed!\n");
		Gtk.main_quit();
    }
}
