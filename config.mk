PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_GNU_SOURCE
CFLAGS   = -std=c99 -Wall
LDFLAGS  = -lm -s
