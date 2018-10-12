CC = gcc
EXEC = "OCR"

CFLAGS = -Wall -Wextra `pkg-config --cflags --libs gtk+-2.0` -I./src
LDLIBS = `pkg-config --cflags --libs gtk+-2.0` -lm -lSDL2

SRC = ${shell find ./src -name "*.c"}
OBJ = ${SRC:.c=.o}

all: $(EXEC)

${EXEC}: ${OBJ}
	${CC} ${OBJ} -o ${EXEC} ${CFLAGS} ${LDLIBS}


