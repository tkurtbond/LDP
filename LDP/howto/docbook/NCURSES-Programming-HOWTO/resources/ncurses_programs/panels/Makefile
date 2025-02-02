# Makefile for panels files

# A few variables

CC=gcc
LIBS=-lpanel -lncurses

SRC_DIR=.
EXE_DIR=../demo/exe

EXES = \
	${EXE_DIR}/panel_browse \
	${EXE_DIR}/panel_hide \
	${EXE_DIR}/panel_resize \
	${EXE_DIR}/panel_simple

${EXE_DIR}/%: %.c | ${EXE_DIR}
	${CC} -o $@ $< ${LIBS}

all:    ${EXES}

${EXE_DIR} :
	mkdir -p ${EXE_DIR}

clean:
	@rm -f ${EXES}
