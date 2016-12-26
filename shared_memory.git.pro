######################################################################
# Automatically generated by qmake (2.01a) ?? 12? 24 21:57:12 2016
######################################################################

TEMPLATE = app
TARGET = client_gui
DEPENDPATH += . include lib src
INCLUDEPATH += . include src

# Input
HEADERS += include/shared_memory_def.h \
           include/shared_memory.h \ 
		   include/client.h \
           include/server.h \
		   include/success_gui.h \
		   include/error_gui.h \
		   include/putting_gui.h \
		   include/getting_gui.h \
		   include/client_gui.h

SOURCES += src/shared_memory.cpp \
		   src/client.cpp \
		   src/client_gui.cpp \
		   src/success_gui.cpp \
           src/error_gui.cpp \
		   src/putting_gui.cpp \
		   src/getting_gui.cpp \
           src/client_gui_main.cpp 
