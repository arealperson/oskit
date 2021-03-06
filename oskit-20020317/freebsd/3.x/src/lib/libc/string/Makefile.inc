#	@(#)Makefile.inc	8.1 (Berkeley) 6/4/93
#	$Id: Makefile.inc,v 1.15 1999/01/19 23:45:48 jdp Exp $

.PATH: ${.CURDIR}/../libc/${MACHINE_ARCH}/string ${.CURDIR}/../libc/string

CFLAGS += -I${.CURDIR}/../libc/locale

# machine-independent string sources
MISRCS+=bcmp.c bcopy.c bzero.c ffs.c index.c memccpy.c memchr.c memcmp.c \
	memcpy.c memmove.c memset.c rindex.c strcasecmp.c strcat.c strchr.c \
	strcmp.c strcoll.c strcpy.c strcspn.c strdup.c strerror.c strlen.c \
	strmode.c strncat.c strncmp.c strncpy.c strpbrk.c strrchr.c strsep.c \
	strspn.c strstr.c strtok.c strxfrm.c swab.c

# machine-dependent string sources
.include "${.CURDIR}/../libc/${MACHINE_ARCH}/string/Makefile.inc"

.if ${LIB} == "c"
MAN3+=	bcmp.3 bcopy.3 bstring.3 bzero.3 ffs.3 index.3 memccpy.3 memchr.3 \
	memcmp.3 memcpy.3 memmove.3 memset.3 rindex.3 strcasecmp.3 strcat.3 \
	strchr.3 strcmp.3 strcoll.3 strcpy.3 strcspn.3 strdup.3 strerror.3 \
	string.3 strlen.3 strmode.3 strpbrk.3 strrchr.3 strsep.3 strspn.3 \
	strstr.3 strtok.3 strxfrm.3 swab.3

MLINKS+=strcasecmp.3 strncasecmp.3
MLINKS+=strcat.3 strncat.3
MLINKS+=strcmp.3 strncmp.3
MLINKS+=strcpy.3 strncpy.3
MLINKS+=strerror.3 perror.3 strerror.3 sys_errlist.3 strerror.3 sys_nerr.3
MLINKS+=strtok.3 strtok_r.3
.endif
