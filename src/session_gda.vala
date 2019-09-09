using GLib;

using Gda;

public class LuDB.GBackend.Session : LuDB.Session, Object {

    private Gda.Connection connection;
    private Backend backend;

    private DataModel tables;

    public void initialize(string directory, string filename) {
        GLib.FileUtils.unlink(filename);
        // TODO support other dbs
        backend    = LuDB.Backends.Sqlite3Backend.instance();
        connection = Gda.Connection.open_from_string("SQLite", "DB_DIR=" + directory + ";DB_NAME=" + filename,
                                                            null, Gda.ConnectionOptions.THREAD_ISOLATED);

        tables = this.connection.execute_select_command(backend.list_tables());
        stdout.printf("TABLES: " + tables.dump_as_string() + "\n");
    }

    public bool is_ready() {
        return true; // FIXME
    }
}