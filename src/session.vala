using GLib;

public interface LuDB.Session : Object {
    
    public abstract void initialize(string directory, string filename);

    public abstract bool is_ready();

}