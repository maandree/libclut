.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

VERSION_MAJOR = 1
VERSION       = 1.2

all: libclut.a libclut.so

libclut.o: libclut.c libclut.h
	$(CC) -c -o $@ libclut.c $(CPPFLAGS) $(CFLAGS)

libclut.lo: libclut.c libclut.h
	$(CC) -fPIC -c -o $@ libclut.c $(CPPFLAGS) $(CFLAGS)

libclut.a: libclut.o
	$(AR) rc $@ libclut.o
	$(AR) s $@

libclut.so: libclut.lo
	$(CC) -shared -Wl,-soname,libclut.so.$(VERSION_MAJOR) -o $@ $(LDFLAGS) libclut.lo

test.o: test.c libclut.h
	$(CC) -c -o $@ test.c $(CPPFLAGS) $(CFLAGS)

test: test.o libclut.a
	$(CC) -o $@ test.o libclut.a $(LDFLAGS)

check: test
	./test

install: libclut.a libclut.so
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libclut.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libclut.so "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(VERSION_MAJOR)"
	ln -sf -- libclut.so.$(VERSION_MAJOR) "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(VERSION)"
	ln -sf -- libclut.so.$(VERSION_MAJOR) "$(DESTDIR)$(PREFIX)/lib/libclut.so"
	cp -- libclut.h "$(DESTDIR)$(PREFIX)/include"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(VERSION_MAJOR)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(VERSION)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libclut.h"

clean:
	-rm -f -- *.o *.a *.so *.lo *.su test

.PHONY: all check install uninstall clean
