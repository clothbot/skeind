######################################################################
# Automatically generated by qmake (2.01a) Fri Nov 12 08:48:12 2010
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . src src/fileformat src/tests/QPolygonTests
INCLUDEPATH += . src

# Input
QT += svg
HEADERS += src/mesh.h \
           src/triangle.h \
           src/line3d.h \
           src/fileformat/dae.h \
           src/fileformat/dxf.h \
           src/fileformat/gdsii.h \
           src/fileformat/stl.h
SOURCES += src/triangle.cpp \
	src/line3d.cpp \
	src/mesh.cpp \
	src/tests/QPolygonTests/main.cpp

unix {
	skeind.path = /usr/bin
	skeind.files = skeind
	INSTALLS += skeind
}
