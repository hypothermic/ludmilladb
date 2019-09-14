# configure.ac

AC_INIT([LudmillaDB],[10.0.0])
AC_CONFIG_SRCDIR([src/ludmilladb.vala])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([no-dist-gzip dist-bzip2])

# Enable silent rules is available
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AM_MAINTAINER_MODE

AC_PROG_CC
AC_PROG_CC_STDC
AM_PROG_VALAC([0.7.0])
AC_PROG_INSTALL
IT_PROG_INTLTOOL([0.35])

pkg_modules="gtk+-3.0 >= 3.2.0"
#LUDMILLADB_PACKAGES="--pkg gtk+-3.0 --pkg libgda-5.0 --pkg libxml-2.0"
LUDMILLADB_PACKAGES="--pkg gtk+-3.0 --pkg libgda-5.0 --pkg gee-0.8"
PKG_CHECK_MODULES(LUDMILLADB, [$pkg_modules])
AC_SUBST(LUDMILLADB_CFLAGS)
AC_SUBST(LUDMILLADB_LIBS)
AC_SUBST(LUDMILLADB_PACKAGES)

PKG_CHECK_MODULES([GDA], libgda-5.0 libxml-2.0)
AC_SUBST([GDA_CFLAGS])
AC_SUBST([GDA_LIBS])
AC_SUBST([GDA_PACKAGES])

GETTEXT_PACKAGE=ludmilladb
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$GETTEXT_PACKAGE"], [Gettext Package])
AC_SUBST(GETTEXT_PACKAGE)
AM_GNU_GETTEXT_VERSION([1.11])
AM_GLIB_GNU_GETTEXT

AC_CONFIG_FILES([
	Makefile
	data/ludmilladb.desktop.in
	data/Makefile
	data/icons/Makefile
	data/icons/16x16/Makefile
	data/icons/22x22/Makefile
	data/icons/24x24/Makefile
	data/icons/32x32/Makefile
	data/icons/48x48/Makefile
	data/icons/scalable/Makefile
	po/Makefile.in
	src/Makefile
	vapi/Makefile
])
AC_OUTPUT
