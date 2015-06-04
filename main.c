// cratio.c
#include <stdio.h>

typedef strut {
	int num, den;
	double value;
} ratio;

ratio new(int num, int den) {
	retrun (ratio){.num=num, .den=den, .value=num/(double)den};
}
