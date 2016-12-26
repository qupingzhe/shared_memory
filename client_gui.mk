#############################################################################
# Makefile for building: client_gui
# Generated by qmake (2.01a) (Qt 4.8.6) on: ?? 12? 25 19:43:39 2016
# Project:  shared_memory.git.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o client_gui.mk shared_memory.git.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Iinclude -Isrc -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/shared_memory.cpp \
		src/client.cpp \
		src/client_gui.cpp \
		src/success_gui.cpp \
		src/error_gui.cpp \
		src/putting_gui.cpp \
		src/getting_gui.cpp \
		src/client_gui_main.cpp moc_error_gui.cpp \
		moc_putting_gui.cpp \
		moc_getting_gui.cpp \
		moc_client_gui.cpp
OBJECTS       = shared_memory.o \
		client.o \
		client_gui.o \
		success_gui.o \
		error_gui.o \
		putting_gui.o \
		getting_gui.o \
		client_gui_main.o \
		moc_error_gui.o \
		moc_putting_gui.o \
		moc_getting_gui.o \
		moc_client_gui.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		shared_memory.git.pro
QMAKE_TARGET  = client_gui
DESTDIR       = 
TARGET        = client_gui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: client_gui.mk $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

client_gui.mk: shared_memory.git.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o client_gui.mk shared_memory.git.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o client_gui.mk shared_memory.git.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/client_gui1.0.0 || $(MKDIR) .tmp/client_gui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/client_gui1.0.0/ && $(COPY_FILE) --parents include/shared_memory_def.h include/shared_memory.h include/client.h include/server.h include/success_gui.h include/error_gui.h include/putting_gui.h include/getting_gui.h include/client_gui.h .tmp/client_gui1.0.0/ && $(COPY_FILE) --parents src/shared_memory.cpp src/client.cpp src/client_gui.cpp src/success_gui.cpp src/error_gui.cpp src/putting_gui.cpp src/getting_gui.cpp src/client_gui_main.cpp .tmp/client_gui1.0.0/ && (cd `dirname .tmp/client_gui1.0.0` && $(TAR) client_gui1.0.0.tar client_gui1.0.0 && $(COMPRESS) client_gui1.0.0.tar) && $(MOVE) `dirname .tmp/client_gui1.0.0`/client_gui1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/client_gui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) client_gui.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_error_gui.cpp moc_putting_gui.cpp moc_getting_gui.cpp moc_client_gui.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_error_gui.cpp moc_putting_gui.cpp moc_getting_gui.cpp moc_client_gui.cpp
moc_error_gui.cpp: include/error_gui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/error_gui.h -o moc_error_gui.cpp

moc_putting_gui.cpp: include/putting_gui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/putting_gui.h -o moc_putting_gui.cpp

moc_getting_gui.cpp: include/getting_gui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/getting_gui.h -o moc_getting_gui.cpp

moc_client_gui.cpp: include/client_gui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/client_gui.h -o moc_client_gui.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

shared_memory.o: src/shared_memory.cpp include/shared_memory.h \
		include/shared_memory_def.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o shared_memory.o src/shared_memory.cpp

client.o: src/client.cpp include/client.h \
		include/shared_memory.h \
		include/shared_memory_def.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o client.o src/client.cpp

client_gui.o: src/client_gui.cpp include/success_gui.h \
		include/error_gui.h \
		include/putting_gui.h \
		include/getting_gui.h \
		include/client.h \
		include/shared_memory.h \
		include/shared_memory_def.h \
		include/client_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o client_gui.o src/client_gui.cpp

success_gui.o: src/success_gui.cpp include/shared_memory_def.h \
		include/success_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o success_gui.o src/success_gui.cpp

error_gui.o: src/error_gui.cpp include/shared_memory_def.h \
		include/error_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o error_gui.o src/error_gui.cpp

putting_gui.o: src/putting_gui.cpp include/shared_memory_def.h \
		include/error_gui.h \
		include/putting_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o putting_gui.o src/putting_gui.cpp

getting_gui.o: src/getting_gui.cpp include/client.h \
		include/shared_memory.h \
		include/shared_memory_def.h \
		include/error_gui.h \
		include/getting_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o getting_gui.o src/getting_gui.cpp

client_gui_main.o: src/client_gui_main.cpp include/client_gui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o client_gui_main.o src/client_gui_main.cpp

moc_error_gui.o: moc_error_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_error_gui.o moc_error_gui.cpp

moc_putting_gui.o: moc_putting_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_putting_gui.o moc_putting_gui.cpp

moc_getting_gui.o: moc_getting_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_getting_gui.o moc_getting_gui.cpp

moc_client_gui.o: moc_client_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_client_gui.o moc_client_gui.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

