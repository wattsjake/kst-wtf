CC = gcc

CFLAGS = -Wall -Wconversion -O3

TARGET = wtf

OBJS = main.o functions.o

INCS = main.h functions.h

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm

%.o: %.c $(INCS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *~