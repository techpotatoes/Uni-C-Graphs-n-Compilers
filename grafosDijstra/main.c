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



//GRAFO AMB
int vetG[9][9] =
   { {0,1,0,1,0,0,0,0,0},  //1
	 {1,0,1,0,1,0,0,0,0},  //2
	 {0,1,0,0,0,1,0,0,0},  //3
	 {1,0,0,0,1,0,1,0,0},  //4
	 {0,1,0,1,0,1,0,1,0},  //5
	 {0,0,1,0,1,0,0,0,1},  //6
	 {0,0,0,1,0,0,0,1,0},  //7
	 {0,0,0,0,1,0,1,0,1},  //8
	 {0,0,0,0,0,1,0,1,0} };//9
//    1 2 3 4 5 6 7 8 9 10

int arestG[9][9] =
   { {0,5,0,4,0,0,0,0,0},  //1
	 {5,0,6,0,3,0,0,0,0},  //2
	 {0,6,0,0,0,2,0,0,0},  //3
	 {4,0,0,0,2,0,4,0,0},  //4
	 {0,3,0,2,0,1,0,2,0},  //5
	 {0,0,2,0,1,0,0,0,8},  //6
	 {0,0,0,7,0,0,0,6,0},  //7
	 {0,0,0,0,2,0,6,0,9},  //8
	 {0,0,0,0,0,8,0,9,0} };//9
//    1 2 3 4 5 6 7 8 9 10

int vetNivelP[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

int vetLamb[9];
int vetT[9];


int buscaMenorLamb(int *vet, int tamvet)  {

	int i = 0;
	int menor = infinit;
	int u = 0;

	//Busca menor valor no vetor Lamb.
	for (i = 0; i < tamvet; i++) {
		if ( (vetLamb[i] < menor) && (vetT[i] == 1) ) {
			menor = vetLamb[i];
			u = i;
		}
	}

	return u;
}

void algoDijstra(int source, int dest) {
	register i = 0;
	int j = 0;

	int u = 0;

	inicializaInfinito(vetLamb, 9);
	inicializaCValor(vetT, 9, 1);

	for (j = 0; j < 9; j++) {
		inicializaCInfinitoOndeZero(arestG[j], 9);
	}


	//Inicializa origem com 0
	vetLamb[source] = 0;


	//Enquanto não é o vetor de destino
	while (1) {
		//Busca no vetor vértive com menor lamb. e verifica se não é o destinio
		u = buscaMenorLamb(vetLamb, 9);
		if (u == dest)
			break;


		//varre arestas adjacentes
		for (i = 0; i < 9; i++) {
			if ( (arestG[u][i] != infinit) && (vetT[i] == 1) ) {
				if (vetLamb[i] > (vetLamb[u] + arestG[u][i]) ) {
					vetLamb[i] = vetLamb[u] + arestG[u][i]; //Atualiza Lamb. se menor
				}
			}
		}

		vetT[u] = 0;
	}

}

int main() {
	int source = 0;
	int dest = 0;

	source = 0;
	dest = 	8;

	algoDijstra(source, dest);
	imprimeVetor(vetLamb, 9);


	return 1;
}
