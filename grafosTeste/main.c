#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


double f(double n) {

	if (n <= 1) return n;
	return (f(n-1) + f(n-2));
}

int main() {



	printf("%f", f(50));


}
