/*
 * exchange is an example of data movement instructions.
 *
 * exchange is implemented with only two data movements (movq) plus an 
 * instruction to return back to the point from which the function was 
 * called (ret).
 *
 * ultimately, this is an example simply of how arguments are passed to 
 * functions in registers. A function returns a value by storing it in 
 * %rax, or in one of the low-order portions of this register.
*/
long exchange(long *xp, long y) {
	long x = *xp;
	*xp = y;
	return x;
}
