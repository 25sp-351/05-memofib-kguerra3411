CC = clang
CFLAGS = -Wall -m64
LDFLAGS = -m64

all: output

output: main.o fibonacci.o memo.o
	$(CC) $(LDFLAGS) -o output main.o fibonacci.o memo.o

main.o: main.c fibonacci.h memo.h
	$(CC) $(CFLAGS) -c main.c

fibonacci.o: fibonacci.c fibonacci.h
	$(CC) $(CFLAGS) -c fibonacci.c
 memo.o: memo.c memo.h fibonacci.h
	$(CC) $(CFLAGS) -c memo.c

clean:
	rm -f output main.o fibonacci.o memo.o
