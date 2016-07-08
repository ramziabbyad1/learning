#a makefile for trap

LINK_TARGET = trap_demo.exe
SOURCES = Main.cpp Additional_fns.cpp Trap.cpp
OBJS = \
	Trap.o \
	Additional_fns.o \
	Main.o	

REBUILDABLES = $(OBJS) $(LINK_TARGET)
#make always runs the first target!!
all: $(LINK_TARGET)
	echo All done

clean:
	rm -f $(REBUILDABLES)
	echo Clean done


%.o : %.cpp
	g++ -g -o $@ -c $<
	echo did it run? done

$(LINK_TARGET) : $(OBJS)
	g++ -g -o $@ $^

Main.o : trap.h additional_fns.h


#Trap.o : 

