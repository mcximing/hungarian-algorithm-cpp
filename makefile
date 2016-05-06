CC = g++
CFLAGS = -std=c++11

test: main.o hung.o
	$(CC) -o test main.o hung.o

hung.o: Hungarian.cpp Hungarian.h
	$(CC) -c Hungarian.cpp -o hung.o
	
main.o: testMain.cpp Hungarian.h
	$(CC) $(CFLAGS) -c testMain.cpp -o main.o

clean:
	-rm main.o hung.o

