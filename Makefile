all: main.o processor.o
	g++ processor.o main.o -o hickory

main.o:
	g++ src/main.cpp -c

processor.o:
	g++ src/processor.cpp -c

test: all
	./hickory programs/add.ssc

clean:
	rm -rf *.o