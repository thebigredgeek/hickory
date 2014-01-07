all: main.o processor.o compiler.o alu.o memory.o io.o registry.o
	g++ main.o processor.o compiler.o alu.o memory.o io.o registry.o -o hickory

main.o:
	g++ src/main.cpp -c

processor.o:
	g++ src/processor.cpp -c

compiler.o:
	g++ src/compiler.cpp -c

alu.o:
	g++ src/alu.cpp -c

memory.o:
	g++ src/memory.cpp -c

io.o:
	g++ src/io.cpp -c

registry.o:
	g++ src/registry.cpp -c

test: all
	./hickory programs/add.ssc

clean:
	rm -rf *.o

rebuild: clean all