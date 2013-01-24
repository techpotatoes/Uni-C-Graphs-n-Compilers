/*
 * main.c
 *
 *  Created on: 14/09/2012
 *      Author: lucas
 */


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

void imprimeVetor(int *vet, int tamvet) {
	int i = 0;

	  for (i = 0; i < tamvet; i++) {
	    printf("  %d  ", vet[i]);
	  }
}



//GRAFO AMB
int vetGP[9][9] =
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

int vetNivelP[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

int buscaDFSProfundidade(int source) {
	register i = 0;
	register j = 0;



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

int vetNivel[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

int buscaBFSAmplitude(int source) {
	register i = 0;
	register j = 0;
	int v = 0;
	int nivelAtual = 0;
	int tem = 1;

	int vetNivel[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
	inicializaNegativo(vetNivel, 9);
	vetNivel[source] = 0;

	//Deve ir nível a nível
	while (tem) {

		tem = 0;
		for(i = 0; i < 9; i++) {
			if (vetNivel[i] == nivelAtual) {
				for (j=0 ; j < 9; j++) {
					if ( ( vetG[i][j] == 1) && (vetNivel[j] < 0) )  { //SE for adjacente e não marcado
						vetNivel[j] = nivelAtual+1;
						tem = 1;
					}
				}
			}
		}
		nivelAtual++;
	}


	imprimeVetor(vetNivel, 9);

}




int main() {


	buscaBFSAmplitude(0);

	return 1;
}
