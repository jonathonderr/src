#	$NetBSD: Makefile.ev64260.inc,v 1.8 2016/07/28 22:46:48 maya Exp $

MKIMG?=	${HOST_SH} ${THISPPC}/compile/walnut-mkimg.sh

TEXTADDR?=	300000

SYSTEM_FIRST_OBJ=	${BOARDTYPE}_locore.o
SYSTEM_FIRST_SFILE=	${THISPPC}/${BOARDTYPE}/${BOARDTYPE}_locore.S

SYSTEM_LD_TAIL_EXTRA+=; \
	echo ${MKIMG} $@ $@.img ; \
	OBJDUMP=${OBJDUMP}; OBJCOPY=${OBJCOPY}; STAT=${TOOL_STAT}; \
		export OBJDUMP OBJCOPY STAT; ${MKIMG} $@ $@.img
