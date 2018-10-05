CC = gcc
CFLAGS = -c -Wall -Wextra -0
LDFLAGS=
EXEC=OCR

all: $(EXEC)

OCR:  main.o ChangeColors.o DetectBloc.o NeuralNetwork.o DetectLetters.o matrix.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c  $< $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
