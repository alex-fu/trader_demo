#Makefile for Futures Trader
CC = g++
INC = -I../include
LIB = -L../lib64 -lthosttraderapi
SRC = main.cpp CtpTraderSpi.cpp CSem.cpp
BIN = ../bin
CFLAGS = -g -Wall -fPIC
TARGET = TestTrader

all:$(TARGET)
	cp $(TARGET) $(BIN)
$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(INC) $(SRC) $(LIB)
clean:
	rm -f $(BIN)/* *.o $(TARGET)
