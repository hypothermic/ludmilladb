using GLib;
using Gee;

using Gda;

public class LuDB.GBackend.Session : LuDB.Session, Object {

    private Gda.Connection connection;
    private Backend backend;

    private DataModel tables {get; set;}

    public async void initialize(Backend backend, string directory, string filename) {
        GLib.FileUtils.unlink(filename);

        this.backend = backend;

        // TODO support other dbs
        connection = Gda.Connection.open_from_string(backend.identifier(), "DB_DIR=" + directory + ";DB_NAME=" + filename,
                                                            null, Gda.ConnectionOptions.THREAD_ISOLATED);

        update_tables();
    }

    public async void update_tables() {
        tables = connection.execute_select_command(backend.list_tables());
    }

    public bool is_ready() {
        return true; // FIXME
    }

    public DataModel get_tables() {
        return tables;
    }

    public Gee.List<Gtk.MenuItem> prepare_menu_items(Gtk.TreePath path, Gtk.TreeViewColumn column) {
        var list = new Gee.ArrayList<Gtk.MenuItem>();
        return list;
    }
}