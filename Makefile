rebuild: clean all

all: compiler.o processor.o main.o
	g++ compiler.o processor.o main.o -o hickory

main.o:
	g++ src/main.cpp -c

processor.o:
	g++ src/processor.cpp -c

compiler.o:
	g++ src/compiler.cpp -c

test: all
	./hickory programs/add.ssc

clean:
	rm -rf *.o