LIBEXT   = so
LIBFLAGS = -shared -Wl,-soname,libclut.$(LIBEXT).$(LIB_MAJOR)

LIBMAJOREXT = $(LIBEXT).$(LIB_MAJOR)
LIBMINOREXT = $(LIBEXT).$(LIB_MAJOR).$(LIB_MINOR)

FIX_INSTALL_NAME = :
