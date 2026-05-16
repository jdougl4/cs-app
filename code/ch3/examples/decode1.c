/*
 * Practice Problem 3.5
 *
 * You are given the following information. A function with prototype
 *
 * void decode1(long *xp, long *yp, long *zp);
 *
 * is compiled into assembly code, yielding the following:
 *
 * decode1:
 * 	movq	(%rdi), %r8
 * 	movq	(%rsi), %rcx
 * 	movq	(%rdx), %rax
 * 	movq	%r8, (%rsi)
 * 	movq	%rcx, (%rdx)
 * 	movq	%rax, (%rdi)
 * 	ret
 *
 * Paramters xp, yp, and zp are stored in registers %rdi, %rsi, and %rdx, 
 * respectively. Write C code for decode1 that will have an effect 
 * equivalent to the assembly code shown.
*/

void decode1(long *xp, long *yp, long *zp) {
	long x = *xp;
	long y = *yp;
	long z = *zp;

	*yp = x;
	*zp = y;
	*xp = z;
}
