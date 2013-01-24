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


//Ciclico
int comp(int M[10][10], int CC[10], int *NC) {

	int i,j,k, ciclico = 0;

	for (i = 0; i < 10; i++) {
		CC[i] = i;
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; i < 10; i++) {
			if (M[i][j] != 0) {
				if (CC[i] == CC[j])
					ciclico = 1;

					int cavx = CC[i];
					for (k=0; k < 10; k++) {
						if (CC[k] == cavx)
							CC[k] = CC[j];
					}

			}
		}
	}


}


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
	    vet[i] = '\n';
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

//Algoritmo de Prim
int algoritPrim() {

	//Grafo de 10 x 10 - Exercicio caderno
	int numVert = 4;
	int infinito = 9999;

	int vetU[numVert];
	int vetL[2][numVert];

	int vetG[numVert][numVert];   //Grafo
	int vetT[numVert][numVert];  //Arvore geradora
	int u = 0;
	int min = 0;
	register i = 0;

	//INICIALIZA GRAFO
	vetG[0][0] = infinito;
	vetG[0][1] = 4;
	vetG[0][2] = 2;
	vetG[0][3] = infinito;

	vetG[1][0] = 4;
	vetG[1][1] = infinito;
	vetG[1][2] = infinito;
	vetG[1][3] = 6;

	vetG[2][0] = 2;
	vetG[2][1] = infinito;
	vetG[2][2] = infinito;
	vetG[2][3] = 8;

	vetG[3][0] = infinito;
	vetG[3][1] = 6;
	vetG[3][2] = 8;
	vetG[3][3] = infinito;

     //....

	//Inicializa caminhos com valor alto - 999
	inicializaInf(vetL[0], numVert);

	inicializaZero(vetU, numVert);

	//Passo 1
	u = 0;
	vetU[u] = 1;
	vetL[0][0] = 0;




	vetU[numVert-1] = infinito;
	while ( vetU[numVert-1] == infinito) {

		//Busca menor vertice no L
		min = infinito;

		//atualiza valores adjacentes no vetor L
		for (i = 0; i < numVert; i++) {
			vetL[0][i] = vetG[u][i];
			vetL[1][i] = u;
		}

		//verifica vetor L - valores que não estão em U E SELECIONA PROX U
		for (i = 0; i < numVert; i++) {
			if (!existeInt(vetU, i, numVert)) {
				if (min < vetL[0][i]) {
					min = vetL[0][i];   //Atualiza valor L
					u = vetL[1][i];
				}
			}
		}


		min = infinito;



	}
}



int main() {


	algoritPrim();

	return 1;
}

