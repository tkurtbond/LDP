# Makefile for JustForFun files

# A few variables

CC=gcc
LIBS=-lncurses

SRC_DIR=.
EXE_DIR=../demo/exe

EXES = \
	${EXE_DIR}/hanoi \
	${EXE_DIR}/life\
	${EXE_DIR}/magic \
	${EXE_DIR}/queens \
	${EXE_DIR}/shuffle \
	${EXE_DIR}/tt

${EXE_DIR}/%: %.c | ${EXE_DIR}
	${CC} -o $@ $< ${LIBS}

all:    ${EXES}

${EXE_DIR} :
	mkdir -p ${EXE_DIR}

clean:
	@rm -f ${EXES}
