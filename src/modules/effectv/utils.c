/*
 * EffecTV - Realtime Digital Video Effector
 * Copyright (C) 2001-2006 FUKUCHI Kentaro
 *
 * utils.c: utilities
 *
 */

#include <math.h>
#include "utils.h"

/*
 * HSI color system utilities
 */
static int itrunc(double f)
{
	int i;

	i=(int)f;
	if(i<0)i=0;
	if(i>255)i=255;
	return i;
}

void HSItoRGB(double H, double S, double I, int *r, int *g, int *b)
{
	double T,Rv,Gv,Bv;

	Rv=1+S*sin(H-2*M_PI/3);
	Gv=1+S*sin(H);
	Bv=1+S*sin(H+2*M_PI/3);
	T=255.999*I/2;
	*r=itrunc(Rv*T);
	*g=itrunc(Gv*T);
	*b=itrunc(Bv*T);
}

/*
 * fastrand - fast fake random number generator
 * Warning: The low-order bits of numbers generated by fastrand()
 *          are bad as random numbers. For example, fastrand()%4
 *          generates 1,2,3,0,1,2,3,0...
 *          You should use high-order bits.
 */
unsigned int fastrand_val;

unsigned int fastrand(void)
{
	return (fastrand_val=fastrand_val*1103515245+12345);
}

void fastsrand(unsigned int seed)
{
	fastrand_val = seed;
}
