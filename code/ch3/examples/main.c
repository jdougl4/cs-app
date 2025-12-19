#include <stdio.h>

/*
 * Along with mstore.c, we can use:
 *
 * gcc -Og -o prog main.c mstore.c
 *
 * to generate an executable program, "prog". This runs the linker 
 * on the set of object-code files (in this case, mstore.o and main.o), 
 * one of which must contain main()
*/

void multstore(long, long, long *);

int main() {
	long d;
	multstore(2, 3, &d);
	printf("2 * 3 --> %ld\n", d);
	return 0;
}

long mult2(long a, long b) {
	long s = a * b;
	return s;
}
