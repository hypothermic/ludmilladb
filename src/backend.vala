using GLib;

public interface LuDB.Backend : Object {

    public abstract string identifier();

    public abstract string list_tables();
    
}