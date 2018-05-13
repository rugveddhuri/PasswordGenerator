all:
	mkdir -p lib
	mkdir -p bin
	gcc -c src/clib.c -o lib/clib.o
	gcc -c PassGen.c -o lib/PassGen.o
	gcc lib/PassGen.o lib/clib.o -o bin/PassGen.exe
	bin/PassGen.exe
compile: 
	mkdir -p lib
	mkdir -p bin
	gcc -c src/clib.c -o lib/clib.o
	gcc -c PassGen.c -o lib/PassGen.o
	gcc lib/PassGen.o lib/clib.o -o bin/PassGen.exe
run:
	bin/PassGen.exe