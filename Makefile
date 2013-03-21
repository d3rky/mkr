#############################################################################
# Makefile for building: build/mkr_qt
# Generated by qmake (2.01a) (Qt 4.8.1) on: Thu Mar 21 23:02:21 2013
# Project:  mkr.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile mkr.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Iinclude -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

SOURCES       = src/describe_task.cpp \
		src/main_qt.cpp \
		src/boundary_conditions/DerichleBoundaryCondition.cpp \
		src/boundary_conditions/NeumanBoundaryCondition.cpp \
		src/plate/mkrpoint.cpp \
		src/plate/plate.cpp \
		src/plate/plate_discret.cpp \
		src/solver/gauss_seidel.cpp \
		src/utils/boundary.cpp \
		src/utils/utils.cpp \
		src/utils/console/solve_task.cpp \
		src/ui/main_window.cpp moc_MainWindow.cpp
OBJECTS       = describe_task.o \
		main_qt.o \
		DerichleBoundaryCondition.o \
		NeumanBoundaryCondition.o \
		mkrpoint.o \
		plate.o \
		plate_discret.o \
		gauss_seidel.o \
		boundary.o \
		utils.o \
		solve_task.o \
		main_window.o \
		moc_MainWindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
		mkr.pro
QMAKE_TARGET  = mkr_qt
DESTDIR       = build/
TARGET        = build/mkr_qt

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

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) build/ || $(MKDIR) build/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: mkr.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
	$(QMAKE) -o Makefile mkr.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
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
	@$(QMAKE) -o Makefile mkr.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/mkr_qt1.0.0 || $(MKDIR) .tmp/mkr_qt1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/mkr_qt1.0.0/ && $(COPY_FILE) --parents include/AbstractBoundaryCondition.h include/Boundary.h include/DerichleBoundaryCondition.h include/GaussSeidel.h include/MkrPoint.h include/NeumanBoundaryCondition.h include/Plate.h include/PlateDiscret.h include/Solver.h include/Utils.h include/ui/MainWindow.h .tmp/mkr_qt1.0.0/ && $(COPY_FILE) --parents src/describe_task.cpp src/main_qt.cpp src/boundary_conditions/DerichleBoundaryCondition.cpp src/boundary_conditions/NeumanBoundaryCondition.cpp src/plate/mkrpoint.cpp src/plate/plate.cpp src/plate/plate_discret.cpp src/solver/gauss_seidel.cpp src/utils/boundary.cpp src/utils/utils.cpp src/utils/console/solve_task.cpp src/ui/main_window.cpp .tmp/mkr_qt1.0.0/ && (cd `dirname .tmp/mkr_qt1.0.0` && $(TAR) mkr_qt1.0.0.tar mkr_qt1.0.0 && $(COMPRESS) mkr_qt1.0.0.tar) && $(MOVE) `dirname .tmp/mkr_qt1.0.0`/mkr_qt1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/mkr_qt1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp
moc_MainWindow.cpp: include/Utils.h \
		include/ui/MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/ui/MainWindow.h -o moc_MainWindow.cpp

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

describe_task.o: src/describe_task.cpp include/Plate.h \
		include/PlateDiscret.h \
		include/MkrPoint.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/Boundary.h \
		include/DerichleBoundaryCondition.h \
		include/NeumanBoundaryCondition.h \
		include/GaussSeidel.h \
		include/Solver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o describe_task.o src/describe_task.cpp

main_qt.o: src/main_qt.cpp include/ui/MainWindow.h \
		include/Utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_qt.o src/main_qt.cpp

DerichleBoundaryCondition.o: src/boundary_conditions/DerichleBoundaryCondition.cpp include/DerichleBoundaryCondition.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/MkrPoint.h \
		include/PlateDiscret.h \
		include/Plate.h \
		include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DerichleBoundaryCondition.o src/boundary_conditions/DerichleBoundaryCondition.cpp

NeumanBoundaryCondition.o: src/boundary_conditions/NeumanBoundaryCondition.cpp include/NeumanBoundaryCondition.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/MkrPoint.h \
		include/PlateDiscret.h \
		include/Plate.h \
		include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NeumanBoundaryCondition.o src/boundary_conditions/NeumanBoundaryCondition.cpp

mkrpoint.o: src/plate/mkrpoint.cpp include/MkrPoint.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/PlateDiscret.h \
		include/Plate.h \
		include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mkrpoint.o src/plate/mkrpoint.cpp

plate.o: src/plate/plate.cpp include/Plate.h \
		include/PlateDiscret.h \
		include/MkrPoint.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plate.o src/plate/plate.cpp

plate_discret.o: src/plate/plate_discret.cpp include/PlateDiscret.h \
		include/MkrPoint.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/Plate.h \
		include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plate_discret.o src/plate/plate_discret.cpp

gauss_seidel.o: src/solver/gauss_seidel.cpp include/GaussSeidel.h \
		include/Solver.h \
		include/Utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gauss_seidel.o src/solver/gauss_seidel.cpp

boundary.o: src/utils/boundary.cpp include/Boundary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o boundary.o src/utils/boundary.cpp

utils.o: src/utils/utils.cpp include/Utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utils.o src/utils/utils.cpp

solve_task.o: src/utils/console/solve_task.cpp include/Plate.h \
		include/PlateDiscret.h \
		include/MkrPoint.h \
		include/AbstractBoundaryCondition.h \
		include/Utils.h \
		include/Boundary.h \
		include/Solver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o solve_task.o src/utils/console/solve_task.cpp

main_window.o: src/ui/main_window.cpp include/ui/MainWindow.h \
		include/Utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_window.o src/ui/main_window.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

