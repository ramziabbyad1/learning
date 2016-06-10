#a simple make and clean
# can be run via make clean; make ex1;
#always use tab for indent
SOURCEFILES=ex1.c ex3.c ex4.c ex5.c ex6.c ex7.c ex8.c ex9.c ex10.c ex11.c
OBJECTFILES=$(SOURCEFILES:.c=.o)

MAINSOURCES=ex1.c ex3.c ex4.c ex5.c ex6.c ex7.c ex8.c ex9.c ex10.c

EXECUTABLES=$(SOURCEFILES:.c=.exe)

EXEC2=$(SOURCEFILES:.c= )

LINK_TARGETS=$(OBJECTFILES:.o=)

REBUILDABLES=$(OBJECTFILES) $(EXECUTABLES) $(EXEC2)

CC=cc

CFLAGS=-Wall -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.exe: %.o
	$(CC) $(CFLAGS) -o $@ $^


all: $(EXECUTABLES) 


clean:
	rm -f $(REBUILDABLES)
