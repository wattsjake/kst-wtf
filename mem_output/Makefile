CC = gcc

CFLAGS = -Wall -Wconversion -O3

TARGET = mem

OBJS = main.o

INCS = main.h

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm

%.o: %.c $(INCS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *~