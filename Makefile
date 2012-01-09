CFLAGS = -O2 -g -Wall -Ilibs
CC = gcc
VPATH = ./libs
#OUTPUT_OPTION = -o ./bin/$@
.SUFFIXES: .c
.PHONY: clean distclean all help install

bin := $(patsubst %.c,%,$(wildcard *.c)) 
obj := $(patsubst %.c,%.o,$(wildcard *.c)) 

all: $(bin)
clean:
	$(RM) $(bin)
	$(RM) $(obj)

# X11 libs 
xw: xw.c
	$(CC) $(CFLAGS) -lX11 $^ $(OUTPUT_OPTION)

# Xscreensave libs 
xss: xss.c ttoms.c char.c
	$(CC) $(CFLAGS) -lX11 -lXss $^  $(OUTPUT_OPTION)

# Normal multi libs 
repeat: repeat.c argstr.c ttoms.c char.c prtime.c
ino: ino.c argstr.c prtime.c
tmp: tmp.c argstr.c char.c
repeat ino ino3 tmp:
	$(CC) $(CFLAGS) $^ $(OUTPUT_OPTION)

# Sqlite3 libs
sql: sql.c argstr.c
privacy: privacy.c
sql privacy:
	$(CC) $(CFLAGS) -lsqlite3 $^ $(OUTPUT_OPTION) 

# ncurses libs
ncurses: ncurses.c
	$(CC) $(CFLAGS) -lncurses $^ $(OUTPUT_OPTION) 


# Installation
install_files := geoip xss privacy repeat
install:
	install $(install_files) ~/bin
