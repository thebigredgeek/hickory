all: main.o processor.o
	g++ processor.o main.o -o build

main.o:
	g++ src/main.cpp -c

processor.o:
	g++ src/processor.cpp -c

run: all
	./build

clean:
	rm -rf *.o