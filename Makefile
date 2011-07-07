#SHELL = /bin/bash
#CFLAGS = `pkg-config  --cflags --libs gtk+-2.0`
CFLAGS = -O2 -g -Wall
CC = gcc
#.SUFFIXES: .c .o
$(patsubst %.c,%,$(wildcard *.c)):

help: main.c hi.c
	echo '$$< $<  $$@ $@  $$% $%  $$^ $^'
obj-m += nothing.o
xss: xss.c ttoms.c char.c
	$(CC) $(CFLAGS) -lXss $^  -o $@
clear: clear.c
	$(CC) $(CFLAGS) -lncurses $^ -o $@

ttoms: ttoms.c char.c 
	$(CC) $(CFLAGS) $^ -o $@

s: s.c
	$(CC)  $^ -o $@	
#	$(CC) `pkg-config --libs heimdal-gssapi` $^ -o $@	
char.o: char.c
	$(CC) $(CFLAGS) -c $^ -o $@
regexp: regexp.c char.o
	$(CC) $(CFLAGS) $^ -o $@
repeat: repeat.c argstr.o
	$(CC) $(CFLAGS) $^ -o $@
sql: sql.c 
	$(CC) $(CFLAGS) -lsqlite3 $^ -o $@
argstr.o: argstr.c
	$(CC) $(CFLAGS) -c $^ -o $@
ino: ino.c argstr.o
	$(CC) $(CFLAGS) $^ -o $@
a: a.c argstr.o
	$(CC) $(CFLAGS) $^ -o $@


.PONY: clean distclean
clean:
	rm *.o
distclean:
	find -maxdepth 1 -executable -exec rm {} \;


