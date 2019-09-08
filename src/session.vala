using GLib;

using Gda;

public class LuDB.GBackend.Session : Object, LuDB.Session {

    private Gda.Connection connection;

    public void initialize(string directory, string filename) {
        GLib.FileUtils.unlink(filename);
        // TODO support other dbs
        this.connection = Connection.open_from_string("SQLite", "DB_DIR=.;DB_NAME=datamodeliterator", null, Gda.ConnectionOptions.THREAD_ISOLATED);
    }

    public bool is_ready() {
        return true; // FIXME
    }
}

public interface LuDB.Session : Object {
    
    public abstract void initialize(string directory, string filename);

    public abstract bool is_ready();

}