
#ifndef _SYS_PARAM_H_
#define _SYS_PARAM_H_

#define	NBBY	8		/* number of bits in a byte. xradio. */
#define	NBPW	sizeof(int)	/* number of bytes per word (integer).xradio. */

/* Bit map related macros. xradio.*/
#define	setbit(a,i)	(((unsigned char *)(a))[(i)/NBBY] |= 1<<((i)%NBBY))
#define	clrbit(a,i)	(((unsigned char *)(a))[(i)/NBBY] &= ~(1<<((i)%NBBY)))
#define	isset(a,i)							\
	(((const unsigned char *)(a))[(i)/NBBY] & (1<<((i)%NBBY)))
#define	isclr(a,i)							\
	((((const unsigned char *)(a))[(i)/NBBY] & (1<<((i)%NBBY))) == 0)

/* Macros for counting and rounding. xradio.*/
#ifndef howmany
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#endif
#define	nitems(x)	(sizeof((x)) / sizeof((x)[0]))
#define	rounddown(x, y)	(((x)/(y))*(y))
#define	rounddown2(x, y) ((x)&(~((y)-1)))          /* if y is power of two .xradio.*/
#define	roundup(x, y)	((((x)+((y)-1))/(y))*(y))  /* to any y .xradio.*/
#define	roundup2(x, y)	(((x)+((y)-1))&(~((y)-1))) /* if y is powers of two .xradio.*/
#define powerof2(x)	((((x)-1)&(x))==0)

/* Macros for min/max. xradio.*/
#define	MIN(a,b) (((a)<(b))?(a):(b))
#define	MAX(a,b) (((a)>(b))?(a):(b))
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

#define ct_assert(e) extern char (*ct_assert(void)) [sizeof(char[1 - 2*!(e)])]

#endif	/* _SYS_PARAM_H_ */
