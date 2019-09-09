using GLib;

public interface LuDB.Session : Object {
    
    public abstract async void initialize(Backend backend, string directory, string filename);

    public abstract bool is_ready();

}