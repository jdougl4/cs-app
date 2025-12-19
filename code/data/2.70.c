/*
 * 2.70
 *
 * Write code for the function with the following prototype:
 *
 * Return 1 when x can be represented as an n-bit, 2's-complement number;
 * 0 otherwise
 * Assume 1 <= n <= w
 *
 * Code must follow the same integer coding rules:
 *
 * 1. Integers are represented in two's complement form
 * 2. Right shifts of signed data are performed arithmetically
 * 3. Data type int is "w" bits long. Can use sizeof(int) << 3 to compute w.
 * 4. Conditionals, loops, switch statements, function calls, and macro
 * invocations are forbidden,
 * 5. Division, modulus, and multiplication are forbidden.
 * 6. Relative comparison operators (<, >, <=, >=) are forbidden.
 *
*/

#include <stdio.h>
#include <assert.h>
#include <limits.h>

// The point is: x << (w - n) >> (w - n) must be equal to x itself
int fits_bits(int x, int n) {
	
	int w = sizeof(int) << 3;	// number of bits in int
	int offset = w - n;
	return (x << offset >> offset) == x;

}


int main(void) {

	int w = sizeof(int) << 3;

	// Basic sanity check
	assert(fits_bits(0, 1) == 1);
	assert(fits_bits(1, 1) == 0);
	assert(fits_bits(-1, 1) == 1);

	// Small n
	assert(fits_bits(1, 2) == 1);	// range -2 .. 1
	assert(fits_bits(2, 2) == 0);

	// Boundary checks for many n
	for (int n = 1; n <= w; n++) {
		int min = (n == w) ? INT_MIN : -(1 << (n - 1));
		int max = (n == w) ? INT_MAX : (1 << (n - 1)) - 1;

		assert(fits_bits(min, n) == 1);
		assert(fits_bits(max, n) == 1);

		// just outside range
		if (n < w) {
			assert(fits_bits(min - 1, n) == 0);
			assert(fits_bits(max + 1, n) == 0);
		}
	}

	// symmetry...
	for (int n = 2; n < w; n++) {
		int val = (1 << (n - 2));
		assert(fits_bits(val, n) == 1);
		assert(fits_bits(-val, n) == 1);
		assert(fits_bits(val << 1, n) == 0);
		assert(fits_bits(-(val << 1) - 1, n) == 0);
	}

	// full word width
	assert(fits_bits(INT_MAX, w) == 1);
	assert(fits_bits(INT_MIN, w) == 1);

	printf("All tests passed.\n");
	return 0;
}
