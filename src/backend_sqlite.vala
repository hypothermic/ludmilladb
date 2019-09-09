using GLib;

public class LuDB.Backends.Sqlite3Backend : LuDB.Backend, Object {

    // singleton
    private static GLib.Once<Sqlite3Backend> _instance;

    public static unowned Sqlite3Backend instance() {
        return _instance.once(() => { return new Sqlite3Backend(); });
    }

    private Sqlite3Backend() {

    }

    public string identifier() {
        return "SQLite";
    }

    public string list_tables() {
        return "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;";
    }
}