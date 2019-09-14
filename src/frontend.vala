using GLib;
using Gee;

using Gtk;
using Gdk;

[GtkTemplate (ui = "/nl/hypothermic/ludmilladb/res/window.ui")]
public class LuDB.Window : Gtk.Window {

	public const int TREEVIEW_DEPTH_DATABASE = 1;
	public const int TREEVIEW_DEPTH_TABLE    = 2;

	[GtkChild]
	private TreeView list_treeview;

	private HashMap<Session, long> sessions = new HashMap<Session, long>();

	construct {
		session_add(LuDB.Backends.Sqlite3Backend.instance(), new LuDB.GBackend.Session(), ".", "ludbx.db");

		list_treeview.button_press_event.connect((event) => {
			if (event.type == EventType.BUTTON_PRESS && event.button == 3) {
				Gtk.Menu menu = new Gtk.Menu();
				Gtk.TreePath path;
				Gtk.TreeViewColumn column;
				int cell_x, cell_y;
				menu.attach_to_widget(list_treeview, null);
				list_treeview.get_path_at_pos((int) event.x, (int) event.y, out path, out column, out cell_x, out cell_y);

				Session session;
				while (path.up()) {
					// navigate up and retrieve 'session' for most top node
				}

				Gee.List<Gtk.MenuItem> a = session.prepare_menu_items(path, column);

				foreach (Gtk.MenuItem i in a) {
					menu.add(i);
				}

				menu.show_all();
				menu.popup_at_pointer(null);
			}
		});		
	}

	[GtkCallback]
    private void window_destroyed() {
		Gtk.main_quit();
	}
	
	public void session_add(Backend backend, Session session, string directory, string filename) {
		Gtk.TreeStore store = list_treeview.model as Gtk.TreeStore;

		Gtk.TreeIter? root_iter = null;
		Gtk.TreeIter? table_iter = null;

		store.append(out root_iter, null);
		store.set(root_iter, 0, backend.identifier() + " at " + directory + "/" + filename, -1);

		session.initialize.begin(backend, directory, filename, (obj, res) => {
			session.initialize.end(res);
			Gda.DataModelIter iter = session.get_tables().create_iter();
			while (iter.move_next()) {
				if (iter.get_value_at(0) == null) {
					break;
				}
				store.append(out table_iter, root_iter);
				store.set(table_iter, 0, iter.get_value_at(0).get_string(), -1);
			}
		});

		sessions.set(session, 0);
	}
}
