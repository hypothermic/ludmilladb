AC_PREREQ(2.59)
AC_INIT(ludmilladb, 1.1)


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([subdir-objects])

AC_PROG_CC
AC_PROG_RANLIB

AC_CONFIG_FILES(Makefile include/str_builder/Makefile src/Makefile src/deployer/Makefile)

PKG_CHECK_MODULES(GTK, gtk+-3.0 >= 3.12)
PKG_CHECK_MODULES(SQLITE, sqlite3 >= 0.22.0)

AC_OUTPUT

