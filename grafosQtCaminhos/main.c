/*
 * main.c
 *
 *  Created on: 14/09/2012
 *      Author: lucas
 */

#define infinit  99999

void inicializaZero(int *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = 0;
	  }
}

void inicializaNegativo(int *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = 0;
	  }
}

void inicializaInfinito(int *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = infinit;
	  }
}

void inicializaCInfinitoOndeZero(int *vet, int tamvet) {
	int i = 0;
	int j = 0;

	  for (i = 0; i < tamvet; i++) {
			if (vet[i] == 0) {
				vet[i] = infinit;
			}
	  }
}

void inicializaCValor(int *vet, int tamvet, int valor) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    vet[i] = valor;
	  }
}

void imprimeVetor(int *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    printf("  %d  ", vet[i]);
	  }
}



//NO CADERNO = QT CAMINHOS
int vetG[4][4] =
   { {0,1,1,0},  //1
	 {1,0,0,1},  //2
	 {1,0,0,0},  //3
	 {0,1,0,0} };//4
//    1 2 3 4

int vetM[4][4] =
   { {0,1,1,0},  //1
	 {1,0,0,1},  //2
	 {1,0,0,0},  //3
	 {0,1,0,0} };//4
//    1 2 3 4

int vetMt[4][4] =
   { {0,1,1,0},  //1
	 {1,0,0,1},  //2
	 {1,0,0,0},  //3
	 {0,1,0,0} };//4
//    1 2 3 4


//Chamada recursivamente
void prodMatricial(  int Mpar[4][4] ) {
	int i = 0;
	int j = 0;
	int k = 0;
	int PROD[4][4];
	int soma = 0;

	for (i=0; i < 4; i++) {
		for (j=0; j < 4; j++) {
			soma = 0;
			for (k=0; k < 4; k++) {
				soma = soma + vetM[i,k] + Mpar[k,j];
			}
			PROD[i,j] = soma;
		}
	}

	//Atualiza matriz
	for (i=0; i < 4; i++) {
		for (j= 0; j < 4; j++) {
			Mpar[i][j] = PROD[i][j];
		}
	}
}

int buscaMenorCaminho(int source, int dest)  {

	int i = 0;
	int u = 0;

	while ( (vetM[source][dest] == 0) && (i < 4)) {

		prodMatricial(*vetMt);
		i++;

	}


	return u;
}

int main() {
	int source = 0;
	int dest = 0;

	source = 0;
	dest = 	2;

	buscaMenorCaminho(source, dest);
	imprimeVetor(vetMt, 9);


	return 1;
}
