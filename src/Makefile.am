bin_PROGRAMS = ludmilladb

ludmilladb_SOURCES = \
	ludmilladb.vala \
	frontend.vala \
	../build/res.gresource.c

INCLUDES = \
	-include config.h \
	$(LUDMILLADB_CFLAGS) \
	-DLOCALEDIR=\""$(localedir)"\" \
	-DPKGDATADIR=\""$(pkgdatadir)"\" \
	-DPKGLIBDIR=\""$(pkglibdir)"\"

VALAFLAGS = \
	--vapidir=$(srcdir)/../vapi --pkg config \
	--gresources=../res/res.gresource.xml ../build/res.gresource.c \
	--gresourcesdir=.. \
	@LUDMILLADB_PACKAGES@

ludmilladb_LDADD = \
	$(LUDMILLADB_LIBS)