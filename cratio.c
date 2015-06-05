// cratio.c
#include <stdio.h>

typedef struct {
	int num, den;
	double value;
} ratio;

ratio new(int num, int den) {
	return (ratio){.num=num, .den=den, .value=num/(double)den};
}

void print_r(ratio r) {
	printf("%i/%i = %g\n", r.num, r.den, r.value);
}

ratio add(ratio left, ratio right) {
	return (ratio){
		.num=left.num*right.den
			+ right.num*left.den,
		.den=left.den * right.den,
                .value=left.value + right.value
		};
}

int main(){
	ratio twothirds = new(2,3);
	ratio quarter= new(1,4);
        print_r(twothirds);
	print_r(quarter);
	print_r(add(twothirds,quarter));

        printf("\nUse of sizeof(x): \n");
	printf("size of two ints: %zu\n", 2*sizeof(int));
	printf("size of a double: %zu\n", sizeof(double));
	printf("size of a ratio struct: %zu\n", sizeof(ratio));
}
