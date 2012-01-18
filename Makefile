CFLAGS = -O2 -g -Wall -Ilibs
CC = gcc
VPATH = ./libs
#OUTPUT_OPTION = -o ./bin/$@
.SUFFIXES: .c
.PHONY: clean distclean all help install uninstall note

bin := $(patsubst %.c,%,$(wildcard *.c)) 
obj := $(patsubst %.c,%.o,$(wildcard *.c)) 

all: $(bin)

clean:
	$(RM) $(obj)

distclean: clean
	$(RM) $(bin)

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
install_files := geoip xss privacy repeat dns
install_to := ~/bin
install: $(install_files)
	install $(install_files) $(install_to)

uninstall:
	cd $(install_to) && \
	$(RM) $(install_files)
