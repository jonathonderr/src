#	$NetBSD: Makefile,v 1.12 2019/01/27 05:16:55 kre Exp $

NOSANITIZER=		# defined

.include <bsd.own.mk>
.include <bsd.init.mk>

RTLD_FUNCS	= \
	_rtld_tls_allocate \
	_rtld_tls_free \

.for _d in ${RTLD_FUNCS}
CPPFLAGS+=	-D${_d}=_elf32_${_d}
.endfor

CPPFLAGS+=	-DELFSIZE=32
LIB=	ldd_elf32

# XXX Force one member
SRCS=	dummy.c

LIBISPRIVATE=	yes
.PATH: ${.CURDIR}/..

.ifdef MLIBDIR
CPPFLAGS+=	-DRTLD_ARCH_SUBDIR=\"${MLIBDIR}\"
.endif

.if ${OBJECT_FMTS:Melf32} != ""
.include "../Makefile.elf"
.endif

.include <bsd.lib.mk>
