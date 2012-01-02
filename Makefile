CFLAGS = -O2 -g -Wall -Ilibs
CC = gcc
VPATH = ./libs
OUTPUT_OPTION = -o ~/bin/$@
.SUFFIXES: .c
.PHONY: clean distclean all help

all: $(patsubst %.c,%,$(wildcard *.c)) 

ec4sed iconv iconv2 read regexp rc recurse ec4sql geoip leak net rc1 rrow:
	$(CC) $(CFLAGS) $@.c $(OUTPUT_OPTION)

# X11 libs 
xw: xw.c
xw xke.c:
	$(CC) $(CFLAGS) -lX11 $^ $(OUTPUT_OPTION)

# Xscreensave libs 
xss: xss.c ttoms.c char.c
	$(CC) $(CFLAGS) -lX11 -lXss $^  $(OUTPUT_OPTION)

# Normal multi libs 
repeat: repeat.c argstr.c ttoms.c char.c prtime.c
ino: ino.c argstr.c prtime.c
ino3: ino3.c argstr.c prtime.c
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

# clean directory
clean:
distclean:
