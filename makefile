compile: include/clib.h src/clib.c PassGen.c
	gcc -c PassGen.c -o PassGen.exe