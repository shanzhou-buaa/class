#include <stdio.h>
#include <math.h>
int main()
{
	double x, y, z, a, b, c, d, e, f, g, s;
	scanf("%lf %lf %lf", &x, &y, &z);
	a = (double) sin (x);
	b = (double) sinh (y);
	c = (double) (1 + fabs (b));
	d = (double) log (c);
	e = (double) acos (a);
	f = (double) pow(e, d);
	g = (double) (2 + cos (z));
	s = (double) (f / g);
	printf("%.2f", s);
	return 0;
}

