using GLib;
using LuDB;

using Gtk;

public static int main(string[] args) {
	Intl.bindtextdomain(Config.GETTEXT_PACKAGE, Config.LOCALEDIR);
	Intl.bind_textdomain_codeset(Config.GETTEXT_PACKAGE, "UTF-8");
	Intl.textdomain(Config.GETTEXT_PACKAGE);

	Environment.set_application_name("LudmillaDB");
	Environment.set_prgname("LudmillaDB");

	Gtk.init(ref args);

	LuDB.Window frontend = new LuDB.Window();
	frontend.show_all();

	Gtk.main();

	return(0);
}

