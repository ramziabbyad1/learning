#  Numerical Methods II, Spring 2012, Courant Institute

#  Makefile for Assignment 3,

#  Jonathan Goodman, goodman@cims.nyu.edu, started February, 2012  (Enter your own data here)

#   Lists of files

SOURCEFILES = vtkWriter.C ellipticSolver.C interpolation.C NewtonSolver.C visit_writer.C

HEADERFILES = heat.h visit_writer.h

OBJECTFILES = $(SOURCEFILES:.C=.o)

#  MAINSOURCES is all C++ files that have a main().  You cannot put more than one of these in an executable.

MAINSOURCES = main.C testInterp.C testSolver.C

OBJECTMAINS = $(MAINSOURCES:.C=.o)


#   Compiler and compiler flags

CC     = g++

CFLAGS = -g 


#    Compile the C++ source files into object files

%.o: %.C $(HEADERFILES) makefile
	$(CC) $(CFLAGS) -c $< -o $@

#    Link and create executables for the testers
#    Run the testers automatically (avoid extra typing).

testInterp: $(OBJECTFILES) testInterp.o makefile
	$(CC) $(CFLAGS) testInterp.o interpolation.o -o testInterp
	

testSolver: $(OBJECTFILES)  testSolver.o makefile
	$(CC) $(CFLAGS) testSolver.o interpolation.o -o testInterp

#    Link & create main executable 

heat: $(OBJECTFILES) main.o makefile
	$(CC) $(CFLAGS) main.o $(OBJECTFILES)  -o heat
	

#   Other stuff


tarball: makefile $(SOURCEFILES) $(MAINSOURCES) $(HEADERFILES)
	tar -cvf Assignment3Code.tar makefile $(SOURCEFILES) $(MAINSOURCES) $(HEADERFILES)