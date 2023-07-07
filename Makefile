.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

OS = linux
# Linux:   linux
# Mac OS:  macos
# Windows: windows 
include mk/$(OS).mk


LIB_MAJOR = 1
LIB_MINOR = 2
LIB_VERSION = $(LIB_MAJOR).$(LIB_MINOR)


HDR = libclut.h
OBJ = libclut.o

LOBJ = $(OBJ:.o=.lo)


all: libclut.a libclut.$(LIBEXT) test
$(OBJ): $(HDR)
$(LOBJ): $(HDR)

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

.c.lo:
	$(CC) -fPIC -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

test: test.o libclut.a
	$(CC) -o $@ test.o libclut.a $(LDFLAGS)

libclut.$(LIBEXT): $(LOBJ)
	$(CC) $(LIBFLAGS) -o $@ $(LOBJ) $(LDFLAGS)

libclut.a: $(OBJ)
	-rm -f -- $@
	$(AR) rc $@ $(OBJ)
	$(AR) -s $@

check: test
	./test

install: libclut.a libclut.$(LIBEXT)
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libclut.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libclut.so "$(DESTDIR)$(PREFIX)/lib/libclut.$(LIBMINOREXT)"
	$(FIX_INSTALL_NAME) "$(DESTDIR)$(PREFIX)/lib/libclut.$(LIBMINOREXT)"
	ln -sf -- "libclut.$(LIBMINOREXT)" "$(DESTDIR)$(PREFIX)/lib/libclut.$(LIBMAJOREXT)"
	ln -sf -- "libclut.$(LIBMINOREXT)" "$(DESTDIR)$(PREFIX)/lib/libclut.$(LIBEXT)"
	cp -- libclut.h "$(DESTDIR)$(PREFIX)/include"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(LIBEXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(LIBMAJOREXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libclut.so.$(LIBMINOREXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libclut.h"

clean:
	-rm -f -- *.o *.a *.so *.lo *.su test

.SUFFIXES:
.SUFFIXES: .lo .o .c

.PHONY: all check install uninstall clean
