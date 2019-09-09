using GLib;

using Gtk;

[GtkTemplate (ui = "/nl/hypothermic/ludmilladb/res/window.ui")]
public class LuDB.Window : Gtk.Window {

	[GtkChild]
	private TreeView list_treeview;

	private List<Session> sessions = new List<Session>();

	construct {
		session_add(LuDB.Backends.Sqlite3Backend.instance(), new LuDB.GBackend.Session(), ".", "ludbx.db");
	}

	[GtkCallback]
    private void window_destroyed() {
		Gtk.main_quit();
	}
	
	public void session_add(Backend backend, Session session, string directory, string filename) {
		Gtk.ListStore store = list_treeview.model as Gtk.ListStore;

		Gtk.TreeIter iter;
		store.append(out iter);
		store.set(iter, 0, backend.identifier() + " at " + directory + "/" + filename);

		session.initialize.begin(backend, directory, filename, (obj, res) => {
			session.initialize.end(res);
			// TODO add child node for each table in gtktreestore
		});

		//session.initialize(directory, filename);
		sessions.append(session);
	}
}
