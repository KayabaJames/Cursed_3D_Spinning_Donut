# Specify the compiler
CC = g++

# Compiling options
CFLAGS = -Wall -std=c++17

# Target file name
TARGET = Main

# Object files
OBJS = Main.o Donut.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	./$(TARGET)

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

Donut.o: Donut.cpp Donut.h
	$(CC) $(CFLAGS) -c Donut.cpp

CursedDonut.o: CursedDonut.cpp Donut.h
	$(CC) $(CFLAGS) -c CursedDonut.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

