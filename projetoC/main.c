/*Includes no LINUX */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*
 * Exemplos e testes em ANSI C
 *
 */

void maiorValor() {
	int a = 0, b = 0, c = 0, maior = 0;

	a = (i == 10 ? )

	printf("\nExibe o maior valor. \nEntre com os valores: ");
	printf("Valor 1:");
	scanf("%d", &a);

	printf("Valor 2:");
	scanf("%d", &b);

	printf("Valor 3:");
	scanf("%d", &c);

	maior = a;
	if (maior < b)
      maior = b;
    if (maior < c)
      maior = c;

	printf("\n\nO maior valor é: %d", maior);

}

void mediaAritmetica() {
	float a = 0.00, b = 0.00, c = 0.00 , m = 0.00;

	printf("\nCalcula media aritmetica.\n Entre com 3 notas:\n");

	printf("Nota 1:");
	scanf("%f", &a);

	printf("Nota 2:");
	scanf("%f", &b);

	printf("Nota 3:");
	scanf("%f", &c);

	m = ((a+b+c)/3);

	printf("A média aritmetica é: %.2f", m);
}


void mediaHarmonica() {
	float a = 0.00, b = 0.00, c = 0.00 , m = 0.00;

	printf("\nCalcula media harmonica.\n Entre com 3 notas:\n");

	printf("Nota 1:");
	scanf("%f", &a);

	printf("Nota 2:");
	scanf("%f", &b);

	printf("Nota 3:");
	scanf("%f", &c);

	m = (3/ ( (1/a)+(1/b)+(1/c) ) );

	printf("A média harmonica é: %.2f", m);
}



int main() {

	//Exemplo aula 1 - Media aritmetica
	maiorValor();
	mediaAritmetica();
	mediaHarmonica();



	return 1;
}
