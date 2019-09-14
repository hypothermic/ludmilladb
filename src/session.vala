using GLib;
using Gee;

using Gda;

public interface LuDB.Session : Object {
    
    public abstract async void initialize(Backend backend, string directory, string filename);

    public abstract bool is_ready();

    // todo abstractify datamodel so we don't need gda
    public abstract DataModel get_tables();

    public abstract Gee.List<Gtk.MenuItem> prepare_menu_items(Gtk.TreePath path, Gtk.TreeViewColumn column);

}