CC = gcc
EXEC = "OCR"

CFLAGS = -Wall -Wextra -I./src
LDLIBS = -lm -lSDL2

SRC = ${shell find ./src -name "*.c"}
OBJ = ${SRC:.c=.o}

all: $(EXEC)

${EXEC}: ${OBJ}
	${CC} ${OBJ} -o ${EXEC} ${CFLAGS} ${LDLIBS}


