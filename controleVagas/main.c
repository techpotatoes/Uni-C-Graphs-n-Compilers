/*Includes no LINUX */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <asm/io.h>



/*
 * main.c
 *
 *  Created on: 10/04/2012
 *      Author: lucas
 *     Ex:
 *     5. Escreva um programa em C que realize o controle das vagas de um estacionamento,
 *     representado através de um vetor. A posição i do vetor marcada com 1 indica que a vaga i
 *     está ocupada; se a posição estiver marcada com 0, a vaga está livre. Inicialmente,
 *     todas as vagas estão livres (o estacionamento tem 20 vagas).
 *     O programa deve constantemente requisitar ao operador a operação a ser executada.
 *     São oferecidas três operações: saída de veículo ('s' ou 'S'), entrada de veículo ('e' ou 'E')
 *     e deixar o programa ('d' ou 'D'). O operador pode ainda exibir a situação atual do
 *     estacionamento (ler o vetor e informar a situação de cada vaga).
 *
 */


//Controle de VAGAS


void montaMenu() {

	system("cls");
	printf("\n\nControle de Vagas de Estacionamento - V1.0 - Lucas Bento\n\n");

	printf("Menu:\n");
	printf("1 - Entrada de veiculo\n");
	printf("2 - Saida de veiculo\n");
	printf("3 - Mostra estacionamento\n");
	printf("4 - Sair\n");
}

void entradaVeiculo(int *vagas) {

	int vaga = 0;


	while (1) {

		printf("\nEntre com o número da vaga a ser preenchida:");
		scanf("%d", &vaga);
		if ( (vaga >= 1) & (vaga <= 20) ) {
			vagas[vaga-1] = 1;
			break;
		}
		printf("\nEntrada inválida:");

	}

}


void saidaVeiculo(int *vagas) {

	int vaga = 0;


	while (1) {

		printf("\nEntre com o número da vaga a ser liberada:");
		scanf("%d", &vaga);
		if ( (vaga >= 1) & (vaga <= 20) ) {
			vagas[vaga-1] = 0;
			break;
		}
		printf("\nEntrada inválida:");

	}
}


void mostraEstacionamento(int *vagas) {

	int i = 0;

	printf("  \n\n\n ESTACIONAMENTO \n\n\n");;

	for (i = 0; i < 20; i++) {

		printf(" %d ", vagas[i]);

	}

}


int main() {

	int i, opc = 0;
	int vagas[20];



	for (i = 0; i < 20; i++)
		vagas[i] = 0;


	do {
		montaMenu();
		scanf("%d", &opc);

		switch (opc) {

			case 1 : entradaVeiculo(vagas); break;
			case 2 : saidaVeiculo(vagas); break;
			case 3 : mostraEstacionamento(vagas); break;
			case 4 : printf("/n/nSaindo.../n/n"); break;
		}


	} while (opc != 4);


	return 1;
}
