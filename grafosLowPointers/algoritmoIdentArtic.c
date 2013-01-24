#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cpio.h>

/*
 * main.c
 *
 *  Created on: 10/08/2012
 *      Author: lucas
 */

//Var amb



void inicializaInf(char *vet, int tamvet) {
	int infinito = 9999;
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = infinito;
	  }
}

void inicializaZero(char *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = 0;
	  }
}

int existeInt(char *vet, int valor, int tamvet) {
  int i = 0;

  for (i = 0; i < tamvet; i++) {
    if (vet[i] == valor)
      return i+1;
  }
  return 0;
}


//GRAFO AMB
/*
int vetG[10][10] =
 	 	 	   { {0,1,1,0,0,0,0,1,0,1},  //1
 	 	 		 {1,0,1,1,1,0,0,1,0,1},  //2
 	 	 		 {1,1,0,1,1,0,0,1,0,0},  //3
 	 	 		 {0,1,1,0,1,0,0,0,0,0},  //4
 	 	 		 {0,1,1,1,0,0,0,0,0,0},  //5
 	 	 		 {0,0,0,0,0,0,1,1,0,0},  //6
 	 	 		 {0,0,0,0,0,1,0,1,0,0},  //7
 	 	 		 {1,1,1,0,0,1,1,0,0,0},  //8
 	 	 		 {0,0,0,0,0,0,0,0,0,0},  //9
 	 	 		 {1,1,0,0,0,0,0,0,0,0} }; //10
//                1 2 3 4 5 6 7 8 9 10
*/
//GRAFO AMB
int vetG[9][9] =
   { {0,1,0,1,0,0,0,0,0},  //1
	 {1,0,1,0,1,0,0,0,0},  //2
	 {0,1,0,0,0,1,0,0,0},  //3
	 {1,0,0,0,1,0,0,0,0},  //4
	 {0,1,0,1,0,0,0,0,0},  //5
	 {0,0,1,0,1,0,0,0,0},  //6
	 {0,0,0,1,0,0,0,1,0},  //7
	 {0,0,0,1,0,0,1,0,1},  //8
	 {0,0,0,0,0,1,0,1,0} };//9
//    1 2 3 4 5 6 7 8 9 10



int nivel[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};


//VERIFICA LOWPOINTERS
int buscaLowpt(int v) {


}


//GERA ARVORE COM BUSCA PROFUNDIDADE
int buscaArvore(int v) {

	int i = 0;
	jaFoi[v] = 1;


	//if (nivel[i] > nivel[j])
	//	tree[i][j] = 1;

	printf("%d \n", v);

	for (i=0 ; i < 10; i++) {
		if ( (vetG[v][i] == 1) && (jaFoi[i] == 0) ) {
			tree[v][i] = 1;
			nivel[i] = nivel[v]+1;
			buscaArvore(i);
		}
	}
}



int main() {

	int i = 0;

	//Arvore gerada por busca de profundidade
	inicializaZero(jaFoi, 10);
	buscaArvore(7);

	printf("\n\n Tree:");
	for (i = 0; i < 10; i++) {
		printf("%d", &tree[i]);
	}


	printf("\n\n Nivel:");
	for (i = 0; i < 10; i++) {
		printf("%d", &nivel[i]);
	}

	getchar();

	return 1;
}

