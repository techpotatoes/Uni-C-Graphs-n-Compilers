#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include "util.h"
#include "token.h"

//Acentos
#include <locale.h>


//Declarações
void menuPrincipal();
void menuAlgoritmos();


int aplicaAlgoritmo(int opc);
int numeroCromatico();
int buscaAmplitude();
int buscaProfundidade();
int componentesConexas();
int componentesBiconexas();
int cicloEuleriano();
int cicloHamiltoniano();
int arvoreGeradoraMinima();
int distanciaPares();


int carregaGrafo(int opc);
int leGrafoArquivo();
int leGrafoMatrizAdj();
int abreArquivoFonte();
void fechaArquivoFonte();
int leLinhaArquivo();
void leToken();


//Var Global
int TAMANHO = 0;
FILE *arqEnt;

char linhaArq[100] = "";
int tamanhoLinha = 0;

int linha = 0;

int token = 0;
int ct_tk = 0;

int grafoQtVertices = 0;



//---------------------------------
//-----------MENUS-----------------
//---------------------------------

void menuPrincipal() {

	system("cls ");
	printf("Software para análise de Grafos.\n");
	printf("Arquivo de Entrada: [DIRETORIO_CORRENTE]/grafo.gr \n");
	printf(" \n\n");
	printf("Menu \n");
	printf("%d-Informar grafo por lista de adjacências.\n", OPINFG);
	printf("%d-Carregar grafo do arquivo..\n", OPIMPG);
	printf("%d-Sair..\n", OPSAIR);


}


void menuAlgoritmos() {

	system("cls");
	printf("O que deseja fazer?\n");
	printf(" \n\n");
	printf("Menu \n");
	printf("%d-Identificação do número cromático.\n", ALGIDENTNUMCR);
	printf("%d-Busca em amplitude..\n", ALGBUSCAAMP);
	printf("%d-Busca em profundidade.\n", ALGBUSCAPROF);
	printf("%d-Identificar componentes conexas..\n", ALGCOMPCONEX);
	printf("%d-Identificar componentes biconexas.\n", ALGCOMPBICONEX);
	printf("%d-Identificar ciclo euleriano.\n", ALGIDENTEULER);
	printf("%d-Identificar ciclo hamiltoniano.\n", ALGIDENTHAMILT);
	printf("%d-Identificar árvore geradora mínima.\n", ALGIDENTARVGERMIN);
	printf("%d-Calcular distância entre todos os pares de vértices.\n", ALGCALCDISTPAR);
	printf("%d-Sair.\n", OPSAIRALG);


}


//---------------------------------
//-----------MAIN-----------------
//---------------------------------

int main(int argc, char *argv[])
{
	int opc = -1;
	int opcA = -1;
	int ok = false;

    //Acentos
    setlocale(LC_ALL, "Portuguese");


	while (opc != OPSAIR) {
		menuPrincipal();
  	    int opcA = -1;

		//Le opção da tela
		opc = leInteiro();

		//Le grafo, matriz ou importado
		if (carregaGrafo(opc))  {
		//Se o grafo esta carregado, mostra algoritmos
			while (opcA != OPSAIRALG) {
				menuAlgoritmos();

				//Le opção da tela
				opcA = leInteiro();

				//Aplica algoritmo
				ok = aplicaAlgoritmo(opcA);

				//Verificar se deu prob. no algorimo
			}

		}


	}




	return 1;
}


//---------------------------------
//-----------LEITURAS--------------
//---------------------------------

int carregaGrafo(int opc) {
	int ok = false;

	//CARREGA GRAFO A SER UTILIZADO
	if (opc == OPIMPG) {
		//Importa grafo do arquivo

		if (leGrafoArquivo())
		  ok = true;
		else
		  erro("Erro ao abrir arquivo fonte do grafo.");



	}
	else if (opc == OPINFG) {
		//Informa grafo

		ok = leGrafoMatrizAdj();
	}

	return ok;
}


int leGrafoArquivo() {
	int ok = false;
	int tamLinha = 0;
	int i = 0;


	linha = 0;
	//Le grafo do arquivo, caminho fixo. em ARQUIVO.
	if (abreArquivoFonte())  {
       tamLinha = 0;
       grafoQtVertices = 0;
       //Numero de vertices
       if (leLinhaArquivo()) {

         tamLinha = strlen(linhaArq) - 1;
         if (tamLinha > 0)
            grafoQtVertices =  atoi(linhaArq);

       }

       //Ligações

       for (i = 0; i < grafoQtVertices; i++) {
         if (leLinhaArquivo()) {
       		while ((ct_tk < tamanhoLinha)) {
	          leToken();
            }
         }
         else
           return false;
       }



       ok = true;
    }
    else {
      ok = false;
    }

	return ok;
}


int leGrafoMatrizAdj() {
	//Le grafo informado por matriz de adj.
	int ok = false;

	printf("Quantos vértices possui o grafo? \n");

	//Le inteiro
	TAMANHO = leInteiro();


	if (TAMANHO > 0) {

		return true;
	}


	return ok;
}



//---------------------------------
//----------ALGORITMOS-------------
//---------------------------------


int aplicaAlgoritmo(int opc) {
	int ok = false;

	switch (opc) {

		case ALGIDENTNUMCR :

			ok = numeroCromatico();

			break;
		case ALGBUSCAAMP:

			//le origem e destino
			ok = buscaAmplitude();

			break;
		case ALGBUSCAPROF:

			ok = buscaProfundidade();

			break;
		case ALGCOMPCONEX:

			ok = componentesConexas();

			break;
		case ALGCOMPBICONEX:

			ok = componentesBiconexas();

			break;
		case ALGIDENTEULER:

			ok = cicloEuleriano();

			break;
		case ALGIDENTHAMILT:

			ok = cicloHamiltoniano();

			break;
		case ALGIDENTARVGERMIN:

			ok = arvoreGeradoraMinima();

			break;
		case ALGCALCDISTPAR:

			ok = distanciaPares();

			break;
	}


	return ok;
}


int numeroCromatico() {
	int ok = false;
	//Identificação do número cromático


	return ok;
}

int buscaAmplitude() {
	int ok = false;

	//Busca em aplitude
	return ok;
}


int buscaProfundidade() {
	int ok = false;

	//Busca em profundidade
	return ok;
}


int componentesConexas() {
	int ok = false;

	//Identifica componentes conexas
	return ok;
}


int componentesBiconexas() {
	int ok = false;

	//Identifica componentes conexas
	return ok;
}


int cicloEuleriano() {
	int ok = false;

	//Identifica ciclo euleriano
	return ok;
}

int cicloHamiltoniano() {
	int ok = false;

	//Identifica ciclo hamiltoniano.
	return ok;
}


int arvoreGeradoraMinima() {
	int ok = false;

	//Identificação de arvore geradora mínima
	return ok;
}


int distanciaPares() {
	int ok = false;

	//Distancia entre todos os pares de vértices.


	return ok;
}

int abreArquivoFonte(){
	if((arqEnt = fopen(ARQUIVO, "rw")) == NULL)
		return 0;
	return 1;
}

void fechaArquivoFonte() {
	fclose(arqEnt);
}


int leLinhaArquivo() {

	if (!feof(arqEnt))
	{
      fgets(linhaArq, 100, arqEnt);
  	  tamanhoLinha = strlen(linhaArq) + 1;
  	  linha++;
  	  ct_tk = 0;
  	  token = 0;
	}
	else
  	  return 0;


	return 1;

}

void leToken() {

	token=0;
	int fim = false;
	int estado = 0;
	int tk = 0;
	char st[100];
	char lexema[100];
	char stt[2];
	char st_lex[2];

    //inicializa
	memset (&st, 0, sizeof (st) );
	memset (&lexema, 0, sizeof (lexema) );
	memset (&stt, 0, sizeof (stt) );
	memset (&st_lex, 0, sizeof (st_lex) );


	while (!fim) {// && (ct_tk < tamanho_expressao)) {

		//Estado q0 - Estado Inicial
		//Estado q1 - Digito

		switch (estado) {

            case 0:
            {
    			if (eFinal( linhaArq[ct_tk])) //FInal de linha
    			{
    				token = 0;
    				fim = true;
    			}
    			else if (eNumero( linhaArq[ct_tk]))
    			{
    				estado = 1;//q1
    				stt[0] = linhaArq[ct_tk];
    				strcat(st, stt);
    			}
    			ct_tk++;
    			break;
            }
            case 1: //q1 - Const Int
		    {
				if (isdigit( linhaArq[ct_tk]) )
				{
					estado = 1;
					stt[0] = linhaArq[ct_tk];
					strcat(st, stt);
					ct_tk++;
				}
				else {
					estado = 0;
					fim = true;
					token = TK_Const_int;
				}

				ct_tk++;
				break;
            }
        }

    }//fim while
    printf("%s", stt);

}


