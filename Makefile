.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

all: libclut.a

libclut.o: libclut.c libclut.h
	$(CC) -c -o $@ libclut.c $(CPPFLAGS) $(CFLAGS)

libclut.a: libclut.o
	$(AR) rc $@ libclut.o
	$(AR) s $@

test.o: test.c libclut.h
	$(CC) -c -o $@ test.c $(CPPFLAGS) $(CFLAGS)

test: test.o libclut.a
	$(CC) -o $@ test.o libclut.a $(LDFLAGS)

check: test
	./test

install: libclut.a
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libclut.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libclut.h "$(DESTDIR)$(PREFIX)/include"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libclut.h"

clean:
	-rm -f -- *.o *.a test

.PHONY: all check install uninstall clean
