bin_PROGRAMS=a.out

a_out_SOURCES=*.c \
              w_chooser/*.c
a_out_CPPFLAGS=$(GTK_CFLAGS)
a_out_LDADD= $(GTK_LIBS) deployer/libdeployer.a ../include/str_builder/libstrbuilder.a
SUBDIRS = deployer

a.out$(EXEEXT): linkbins $(a_out_OBJECTS) $(a_out_DEPENDENCIES) $(EXTRA_a_out_DEPENDENCIES) 
	@rm -f a.out$(EXEEXT)
	$(AM_V_CCLD)$(LINK) $(a_out_OBJECTS) $(a_out_LDADD) ../build/*.o $(LIBS)

linkbins:
	rm -f ../build/*
	mkdir -p ../build
	ld -r -b binary ../res/window.ui -o ../build/window.ui.o
	ld -r -b binary ../res/window.css -o ../build/window.css.o
	ld -r -b binary ../res/ico/baseline-add-24px.svg -o ../build/add.svg.o
	ld -r -b binary ../res/ico/baseline-insert_drive_file-24px.svg -o ../build/file.svg.o
