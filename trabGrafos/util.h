//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#ifndef UTIL_H_
#define UTIL_H_


//Costantes
const int false = 0;
const int true = 1;


enum {
	//Opções menu principal
	OPINFG = 1,
	OPIMPG = 2,
	OPSAIR = 3,

	//Opções menu algoritmos
	ALGIDENTNUMCR = 1,
	ALGBUSCAAMP = 2,
	ALGBUSCAPROF = 3,
	ALGCOMPCONEX = 4,
	ALGCOMPBICONEX = 5,
	ALGIDENTEULER = 6,
	ALGIDENTHAMILT = 7,
	ALGIDENTARVGERMIN = 8,
	ALGCALCDISTPAR = 9,
	OPSAIRALG = 10
};




int leInteiro() {
	char op;
	int opc = 1;

	//Le inteiro
	while (true) {
		op = getchar();
		opc = atoi(&op);

		if (opc > 0)
			break;
	}

	return opc;

}


#endif /* UTIL_H_ */
