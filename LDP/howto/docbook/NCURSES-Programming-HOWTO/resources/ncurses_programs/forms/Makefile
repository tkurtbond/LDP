# Makefile for forms files

# A few variables

CC=gcc
LIBS=-lform -lncurses

SRC_DIR=.
EXE_DIR=../demo/exe

EXES = \
	${EXE_DIR}/form_attrib\
	${EXE_DIR}/form_options\
	${EXE_DIR}/form_simple\
	${EXE_DIR}/form_win \

${EXE_DIR}/%: %.c | ${EXE_DIR}
	${CC} -o $@ $< ${LIBS}

all:    ${EXES}

${EXE_DIR} :
	mkdir -p ${EXE_DIR}

clean:
	@rm -f ${EXES}
