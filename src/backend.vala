using GLib;

public interface LuDB.Backend : Object {

    public abstract string identifier();

    public abstract string list_tables();
    public abstract string rename_table(string table_name, string new_name);
    
}