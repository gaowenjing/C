#SHELL = /bin/bash
CFLAGS = -O2 -g -Wall
CC = gcc
.SUFFIXES: .c .o
.PHONY: distclean all help

all: repeat ino lid xss tmp fork fork2 xw

# X11 libs 
xke.o: xke.c
fork2: fork2.c xke.o
fork: fork.c xke.o
xw: xw.c
xw fork fork2 xke.o:
	$(CC) $(CFLAGS) -lX11 $^ -o $@

# Xscreensave libs 
xss: xss.c ttoms.o char.o
	$(CC) $(CFLAGS) -lXss $^  -o $@

# Normal multi libs 
ttoms: ttoms.c char.o 
regexp: regexp.c char.o
repeat: repeat.c argstr.o time.o ttoms.o char.o
ino: ino.c argstr.o time.o
tmp: tmp.c argstr.o char.o time.o
ttoms regexp repeat ino tmp:
	$(CC) $(CFLAGS) $^ -o $@

# Sqlite3 libs
sql: sql.c 
	$(CC) $(CFLAGS) -lsqlite3 $^ -o $@ 

# Modules 
obj-m += m.o
m:
	make -C /kernel M=$(PWD) modules

# clean directory
distclean:
	rm *.o
	find -maxdepth 1 -executable -exec rm {} \;

# print Makefile help for me 
help: xss.c ttoms.c char.o
	@echo TARGET ... : PREREQUISITES ...
	@echo help: xss.c ttoms.c char.o 
	@echo -e '\t$$< = $<\n\t$$@ = $@\n\t$$% = $%\n\t$$^ = $^'


