#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include <ctype.h>
#include <cpio.h>

//Declaração de procedimentos
int palavraReservada(char st[20], int *tk);
int eFinal(char c);
int eNumero(char c);
int eLetra(char c);
int leArquivo();
void leToken();
void verifTokens();
int abreArquivoFonte();
void fechaArquivoFonte();
void fechaArquivoFonte();
int abreArquivoToken();
void fechaArquivoToken();
int verifGramatica();

//GRAMATICAS
int estrutRetorne();
int estrutVar();
int estrutFuncao();
int estrutProcedimento();
int estrutListaVar1();
int estrutListaVar();
int estrutListaDecl();
int estrutDecl1();
int estrutDecl();
int estrutTipo();
int estrutTipoVetor();
int estrutBloco();
int estrutComandos();
int estrutPara();
int estrutEnquanto();
int estrutRepita();
int estrutLeitura();
int estrutEscreva();
int estrutSe();
int estrutSe1();
int estrutAtribuicao();
int estrutListaExpressao();
int estrutIndiceVetor();
int estrutOperadorLogico();
int estrutOperadorRelacional();
int estrutOperador ();
int estrutOperando();
int estrutExpressao();
int estrutExpressaoLogica();
int estrutExpressaoLogica1();
int estrutExpressaoArit();
int estrutExpressaoArit1();
int estrutExpressaoLiteral();
int estrutExpressaoRelacional();
int estrutExpressaoRelacional1();
int estrutChamadaFuncao();
int estrutParametro();
int estrutParametrosFormais();
int estrutRetorno();



const int true = 1;
const int false = 0;

FILE *arqF;
char nomearq_fonte[30] = "ENTRADA.ALG";

FILE *arqTk;
char nomearq_token[30] = "Saida.lex";


int token = 0;
int ct_tk = 0;
int GERA_LEXICO = 0;
int linha = 0;

char expressao[500] = "";

//Verificar antes de mandar cada linha
int tamanho_expressao = 0;


void erroS(char msg[80]) {
	printf("Erro de sintaxe. Linha %d  Coluna %d", linha, ct_tk);
	printf("   %s \n\n", msg);

	exit(1);
}

int eFinal(char c) {

	if (toascii(c) == 0)
		return 1;
	else
		return 0;
}

int eNumero(char c) {

	if (toascii(c) == 0)
		return 0;
	if ( isdigit(c) )
		return 1;
	else
		return 0;
}

int eLetra(char c) {
	if ( (c >= 'a') && (c <= 'z') )
		return 1;
	else if ( (c >= 'A') && (c <= 'Z') )
		return 1;
	else
		return 0;
}


int palavraReservada(char st[20], int *tk) {

	//PALAVRAS LINGUAGEM
	if ( strcmp(st,"algoritmo") == 0) {
		*tk = TK_Algoritmo;
		return true;
	}
	else if ( strcmp(st,"var") == 0) {
		*tk = TK_Var;
		return true;
	}
	else if ( strcmp(st,"inicio") == 0) {
		*tk = TK_Inicio;
		return true;
	}
	else if ( strcmp(st,"escreva") == 0) {
		*tk = TK_Escreva;
		return true;
	}
	else if ( strcmp(st,"fimalgoritmo") == 0) {
		*tk = TK_Fim_Alg;
		return 1;
	}
	else if ( strcmp(st,"para") == 0) {
		*tk = TK_Para;
		return 1;
	}
	else if ( strcmp(st,"de") == 0) {
		*tk = TK_De;
		return 1;
	}
	else if ( strcmp(st,"ate") == 0) {
		*tk = TK_Ate;
		return 1;
	}
	else if ( strcmp(st,"faca") == 0) {
		*tk = TK_Faca;
		return 1;
	}
	else if ( strcmp(st,"fimpara") == 0) {
		*tk = TK_Fimpara;
		return 1;
	}
	else if ( strcmp(st,"repita") == 0) {
		*tk = TK_Repita;
		return 1;
	}
	else if ( strcmp(st,"enquanto") == 0) {
		*tk = TK_Enquanto;
		return 1;
	}
	else if ( strcmp(st,"fimenquanto") == 0) {
		*tk = TK_FimEnquanto;
		return 1;
	}
	else if ( strcmp(st,"se") == 0) {
		*tk = TK_Se;
		return 1;
	}
	else if ( strcmp(st,"entao") == 0) {
		*tk = TK_Entao;
		return 1;
	}
	else if ( strcmp(st,"senao") == 0) {
		*tk = TK_Senao;
		return 1;
	}
	else if ( strcmp(st,"fimse") == 0) {
		*tk = TK_Fimse;
		return 1;
	}
	else if ( strcmp(st,"escreva") == 0) {
		*tk = TK_Escreva;
		return 1;
	}
	else if ( strcmp(st,"leia") == 0) {
		*tk = TK_Leia;
		return 1;
	}
	else if ( strcmp(st,"inteiro") == 0) {
		*tk = TK_Inteiro;
		return 1;
	}
	else if ( strcmp(st,"real") == 0) {
		*tk = TK_Real;
		return 1;
	}
	else if ( strcmp(st,"e") == 0) {
		*tk = TK_E;
		return 1;
	}
	else if ( strcmp(st,"ou") == 0) {
		*tk = TK_OU;
		return 1;
	}
	else if ( strcmp(st,"literal") == 0) {
		*tk = TK_Literal;
		return 1;
	}
	else if ( strcmp(st,"vetor") == 0) {
		*tk = TK_Vetor;
		return 1;
	}
	else if ( strcmp(st,"escreval") == 0) {
		*tk = TK_EscrevaL;
		return 1;
	}
	else if ( strcmp(st,"falso") == 0) {
		*tk = TK_Falso;
		return 1;
	}
	else if ( strcmp(st,"verdadeiro") == 0) {
		*tk = TK_Verdadeiro;
		return 1;
	}
	else if ( strcmp(st,"funcao") == 0) {
		*tk = TK_Funcao;
		return 1;
	}
	else if ( strcmp(st,"fimfuncao") == 0) {
		*tk = TK_Fimfuncao;
		return 1;
	}
	else if ( strcmp(st,"procedimento") == 0) {
		*tk = TK_Procedimento;
		return 1;
	}
	else if ( strcmp(st,"fimprocedimento") == 0) {
		*tk = TK_Fimprocedimento;
		return 1;
	}
	else if ( strcmp(st,"retorne") == 0) {
		*tk = TK_Retorne;
		return 1;
	}
	else if ( strcmp(st,"nao") == 0) {
		*tk = TK_NAO;
		return 1;
	}
	else if ( strcmp(st,"passo") == 0) {
		*tk = TK_Passo;
		return 1;
	}
	//FUNCOES LINGUAGEM
	else if ( strcmp(st,"abs") == 0) {
		*tk = TK_Abs;
		return 1;
	}
	else if ( strcmp(st,"raizq") == 0) {
		*tk = TK_Raizq;
		return 1;
	}
	else if ( strcmp(st,"sen") == 0) {
		*tk = TK_Sen;
		return 1;
	}
	else if ( strcmp(st,"cos") == 0) {
		*tk = TK_Cos;
		return 1;
	}
	else if ( strcmp(st,"int") == 0) {
		*tk = TK_Int;
		return 1;
	}

	return 0;
}


void leToken()
{
	token=0;
	int fim = false;
	int estado = 0;
	int tk = 0;
	char st[100];
	char lexema[100];
	char stt[2];
	char st_lex[2];
	int ok = 1;

    //inicializa
	memset (&st, 0, sizeof (st) );
	memset (&lexema, 0, sizeof (lexema) );
	memset (&stt, 0, sizeof (stt) );
	memset (&st_lex, 0, sizeof (st_lex) );


	if ( (ct_tk >= tamanho_expressao) ||
		(eFinal( expressao[ct_tk])) ) //FInal de linha
		ok = leArquivo();


	while (!fim) {// && (ct_tk < tamanho_expressao)) {

		//TOkens Caract.
		if (eFinal( expressao[ct_tk])) //FInal de linha
		{
			ok = leArquivo();
			//
		}

		//if (ok == 1) {


			//Estado q0 - Estado Inicial
			//Estado q1 - Digito
			//Estado q2 - Digito e ponto
			//Estado q3 -

			switch (estado) {

			case 0:
			{
				if (eFinal( expressao[ct_tk])) //FInal de linha
				{
					token = 0;
					fim = true;
				}

				if (eNumero( expressao[ct_tk]))
				{
					estado = 1;//q1
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
				}
				else if (expressao[ct_tk] == '-') {//q5
					token = TK_Menos;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '+') {//q6
					token = TK_Mais;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == ':') {//q7
					token = TK_Dois_pontos;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == ';') {//q8
					token = TK_Ponto_e_virgula;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '*') {//q9
					token = TK_Mult;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '%') {//q11
					token = TK_Resto;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == ')') {//q18
					token = TK_Fecha_par;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '(') {//q28
					token = TK_Abre_par;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == ',') {//q12
					token = TK_Virgula;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '=') {//q13
					token = TK_Igual;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '<') //q14
					estado = 14;
				else if (expressao[ct_tk] == '/') {//q29
					token = TK_Divide;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '>') //q20
					estado = 20;
				else if (expressao[ct_tk] == '[') {//q21
					token = TK_AbreColchete;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == ']') {//q22
					token = TK_FechaColchete;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '.') //q23
					estado = 23;
				else if (expressao[ct_tk] == '^') {//q27
					token = TK_Potenciacao;
					fim = true;
					st_lex[0] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '"') //q33
					estado = 33;
				else if (eLetra(expressao[ct_tk]))
				{
					estado = 30; //q30
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
				}


				ct_tk++;
				break;
			}
			case 1: //q1 - Const Int
			{
				if (isdigit( expressao[ct_tk]) )
				{
					estado = 1;
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
					ct_tk++;
				}
				else if (expressao[ct_tk] == '.')
				{
					estado = 2;
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
				}
				else {
					estado = 0;
					fim = true;
					token = TK_Const_int;
				}
				break;
			}
			case 2: //q2 - Real ou tamanho vetor...
			{
				if (eNumero(expressao[ct_tk]) )
				{
					estado = 3;
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
				}
				else if (expressao[ct_tk] == '.') { //q4 - Except
					estado = 0;
					fim = 1;
					token = TK_Const_int;
					ct_tk--; //Volta um para achar ..
				}
				else {
					token = 0;
				}

				ct_tk++;
				break;
			}
			case 3: //q3 - Const Real
			{
				if (eNumero(expressao[ct_tk]) )
				{
					estado = 3;
					ct_tk++;
				}
				else {
					estado = 0;
					fim = true;
					token = TK_Const_real;
				}
				break;
			}
			case 14: //q14 - Menor
			{
				if (expressao[ct_tk] == '=') { //q15
					estado = 0;
					fim = true;
					token = TK_MenorIgual;
					ct_tk++;
					st_lex[0] = expressao[ct_tk-1];
					st_lex[1] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '-') { //q26
					estado = 0;
					fim = true;
					token = TK_Atrib;
					ct_tk++;
					st_lex[0] = expressao[ct_tk-1];
					st_lex[1] = expressao[ct_tk];
				}
				else if (expressao[ct_tk] == '>') { //q16
					estado = 0;
					fim = true;
					token = TK_Diferente;
					ct_tk++;
					st_lex[0] = expressao[ct_tk-1];
					st_lex[1] = expressao[ct_tk];
				}
				else { //q15
					estado = 0;
					fim = true;
					token = TK_Menor;
					st_lex[0] = expressao[ct_tk];
				}
				break;
			}
			case 20: //q20 - Maior
			{
				if (expressao[ct_tk] == '=') { //q19
					estado = 0;
					fim = true;
					token = TK_MaiorIgual;
					st_lex[0] = expressao[ct_tk-1];
					st_lex[1] = expressao[ct_tk];
				}
				else { //q20
					estado = 0;
					fim = true;
					token = TK_Maior;
					st_lex[0] = expressao[ct_tk];
				}
				ct_tk++;
				break;
			}
			case 23: //q20 - Ponto
			{
				if (expressao[ct_tk] == '.') { //q24
					estado = 0;
					fim = true;
					token = TK_pontoponto;
					st_lex[0] = expressao[ct_tk-1];
					st_lex[1] = expressao[ct_tk];
				}
				else {
					token = 0;
				}
				ct_tk++;
				break;
			}
			case 33: //q33 - String
			{
				if (expressao[ct_tk] != '"')  //q24
				{
					estado = 33;
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
					ct_tk++;
				}
				else {

					estado = 0;
					fim = true;
					token = TK_String;
					ct_tk++;
				}
				break;
			}
			case 30: //q33 - String
			{
				if ( eNumero(expressao[ct_tk]) || eLetra(expressao[ct_tk])) //q30
				{
					stt[0] = expressao[ct_tk];
					strcat(st, stt);
					estado = 30;
					ct_tk++;
				}
				else if (palavraReservada(st,&tk)) //q17
				{
					estado = 0;
					fim = true;
					token = tk;
				}
				else //q30
				{
					estado = 0;
					fim = true;
					token = TK_Ident;
				}
				break;
			}
			}
		//}
		//else fim = true;

	}

	//Escreve para arquivo se for somente GERA_LEXICO
	memset (&lexema, 0, sizeof (lexema) );

}

int estrutRetorne() {
	if ( estrutOperando()){
		return true;
	}
	else
		return false;
}

int estrutVar() {  //Variáveis
	if ( estrutDecl() ) {
		return true;
	}
	return false;
}

int estrutFuncao() {
	if (token == TK_Ident) {
		leToken();
		if ( token == TK_Abre_par ) {
			leToken();
			if (estrutParametrosFormais() ) {
				if (token == TK_Fecha_par) {
					leToken();
					if (token == TK_Dois_pontos) {
						leToken();
						if (estrutRetorno()) {
							//Com declaração de variáveis
							if (token == TK_Var) {
								leToken();
								if ( estrutVar() ) {
									if (token == TK_Inicio) {
										leToken();
										if (estrutBloco() ) {
											if (token == TK_Fimfuncao) {
											  	leToken();
												return true;
											}
											else
												erroS("Esperava fimfuncao");
										}
									}
									else
										erroS("Esperava inicio");
								}
							}
							//Sem declaração de variáveis
							if (token == TK_Inicio) {
								leToken();
								if (estrutBloco() ) {
									if (token == TK_Fimfuncao) {
										leToken();
										return true;
									}
									else
										erroS("Esperava fimfuncao");
								}
							}
							else
								erroS("Esperava inicio");
						}
					}
					else
						erroS("Esperava dois pontos");
				}
				else
					erroS("Esperava fecha parenteses");
			}
		}
		else
			erroS("Esperava abre parenteses");
	}
	else
	    erroS("Esperava nome da funcao");

	return false;

}

int estrutProcedimento() {
	if (token == TK_Ident) {
		leToken();
		if ( token == TK_Abre_par ) {
			leToken();
			if (estrutParametrosFormais() ) {
				if (token == TK_Fecha_par) {
					leToken();
					if (token == TK_Var) {
						leToken();
						if ( estrutVar() ) {
							if (token == TK_Inicio) {
								leToken();
								if (estrutBloco() ) {
									if (token == TK_Fimprocedimento) {
										leToken();
										return true;
									}
									else
										erroS("Esperava fimprocedimento");
								}
							}
							else
								erroS("Esperava inicio");
						}
					}
					//Sem declaração de variáveis
					if (token == TK_Inicio) {
						leToken();
						if (estrutBloco() ) {
							if (token == TK_Fimprocedimento) {
								leToken();
								return true;
							}
							else
								erroS("Esperava fimprocedimento");
						}
					}
				}
				else
					erroS("Esperava fecha parenteses");
			}
		}
		else
			erroS("Esperava abre parenteses");
	}
	erroS("Esperava nome da função");
	return false;
}

int estrutListaVar1() {  //Declaração de variáveis
	if (token == TK_Virgula) {
		leToken();
		if (token == TK_Ident) {
			leToken();
			if ( estrutListaVar1() )
				return true;
		}
		else
			erroS("Esperava identificador");
	}
	else
	  return true;
}

int estrutListaVar() {  //Declaração de variáveis
	if ( estrutListaVar1() ) {
		return true;
	}
}

int estrutListaDecl() {  //Declaração de variáveis
	if (token == TK_Procedimento) {
		leToken();
		if (estrutProcedimento()) {
			return true;
		}
	}
	else if (token == TK_Funcao) {
		leToken();
		if (estrutFuncao()) {
			return true;
		}
	}
	else if (token == TK_Ident) {
		leToken();
	    if ( estrutListaVar() ) {
	    	if ( token == TK_Dois_pontos) {
	    		leToken();
	    		if (estrutTipo()) {
	    			if (token == TK_Ponto_e_virgula) {
	    				leToken();
	    			    return true;
	    			}
					else
						erroS("Esperava ponto e virgula");
	    		}
	    	}
			else
				erroS("Esperava dois pontos");
	    }
	}
	return false;
}

int estrutDecl() {  //Declaração de variáveis
	if ( estrutDecl1() ) {
		return true;
	}

}

int estrutDecl1() {  //Declaração de variáveis
	if (estrutListaDecl()) {
		if (estrutDecl()) {
			return true;
		}
	}
    //se for outras lista de variáveis continua, senão passa para o próximo...
	return true;
}




int estrutTipo() {  //Declaração de variáveis
	if (token == TK_Inteiro) {
		leToken();
		return true;
	}
	else if (token == TK_Real) {
		leToken();
		return true;
	}
	else if (token == TK_Logico)	{
		leToken();
		return true;
	}
	else if (token == TK_Literal) {
		leToken();
		return true;
	}
	else if (token == TK_Vetor) {
		leToken();
		if (estrutTipoVetor()) {
			return true;
		}
	}
	erroS("Tipo de variável não reconhecido.");
	return false;
}

int estrutTipoVetor() {  //Declaração de variáveis
		if (token == TK_AbreColchete) {
			leToken();
			if ( token == TK_Const_int) {
				leToken();
				if (token == TK_pontoponto) {
					leToken();
					if (token == TK_Const_int) {
						leToken();
						//unidimensional
						if (token == TK_FechaColchete) {
							leToken();
							if (token == TK_De) {
								leToken();
								if (estrutTipo()) {
									return true;
								}
							}
							else
								erroS("Esperava token .de.");
						}
						//bidimensional
						if (token == TK_Virgula) {
							leToken();
							if (token == TK_Const_int) {
								leToken();
								if (token == TK_pontoponto) {
									leToken();
									if (token == TK_Const_int) {
										leToken();
										if (token == TK_FechaColchete) {
											leToken();
											if (token == TK_De) {
												leToken();
												if (estrutTipo() ) {
													return true;
												}
											}
											else
												erroS("Esperava token .de.");
										}
										else
											erroS("Esperava fecha colchete");
									}
								}
							}
							else
								erroS("Esperava uma constante inteira");
						}

					}
					else
						erroS("Esperava uma constante inteira");
				}
				else
					erroS("Esperava ponto ponto");
			}
			else
				erroS("Esperava uma constante inteira");
		}
		else
			erroS("Esperava abre colchete");
	return false;
}

int estrutBloco() {
	if (estrutComandos()) { //Bloco comandos
		return true;
	}
	else
		return false;
}

int estrutComandos() {
	if (token == TK_Ident) {
		leToken();
		if ( estrutAtribuicao() ) { //Bloco ATRIBUICAO
			if (estrutComandos())
				return true;
		}
		if (token == TK_Abre_par) {
			leToken();
			if (estrutChamadaFuncao()) {
				if (estrutComandos())
					return true;
			}

		}

		erroS("Esperava atribuicao ou abre parenteses");
		return false;

	}
	else if (token == TK_Leia) { //Bloco LEITURA
		leToken();
		if (estrutLeitura()) {
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if (token == TK_Escreva) { //Bloco Escreva
		leToken();
		if (estrutEscreva()) {
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if (token == TK_Se) { //Bloco CONDICIONAL
		leToken();
		if (estrutSe()) 	{
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if (token == TK_Repita) {  //Bloco REPETICAO
		leToken();
		if (estrutRepita()) {
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if (token == TK_Enquanto) {  //Bloco REPETICAO
		leToken();
		if (estrutEnquanto()) {
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if (token == TK_Para) {  //Bloco REPETICAO
		leToken();
		if (estrutPara()) {
			if (estrutComandos()) {
				if (estrutComandos()) {
					return true;
				}
			}
		}

		return false;
	}
	else if (token == TK_Retorne) {  //Bloco Retorne
		leToken();
		if ( estrutRetorne() ) {
			if (estrutComandos())
				return true;
		}

		return false;
	}
	else if ( (token == TK_Abs) || (token == TK_Raizq) || (token == TK_Sen) || (token == TK_Cos) || (token == TK_Int) ) { //Chamada função pré-defi
		leToken();
		if (token == TK_Abre_par) {
			leToken();
			if ( estrutChamadaFuncao() ) {
				if (estrutComandos())
					return true;
			}
		}
		else
		  erroS("Esperava abre parenteses");
		return false;
	}
	else if (token == TK_Fecha_par)          //FECHA PARENTESES PERDIDO
		erroS("Faltou abre parenteses");
	return true;

}

int estrutPara() {
	if (token == TK_Ident) {
		leToken();
		if (token == TK_De)	 {
			leToken();
			if (estrutExpressao() ) {
				if (token == TK_Ate) {
					leToken();
					if (estrutExpressao() ) {
						if (token == TK_Faca) {
							leToken();
							if (estrutComandos()) {
								if (token == TK_Fimpara) {
									leToken();
									return true;
								}
								else
									erroS("Esperava fimpara");
							}
						}
						else
							erroS("Esperava token .faca.");
					}
				}
				else
					erroS("Esperava token .ate.");
			}
		}
		else
			erroS("Esperava token .de.");
	}
	else
		erroS("Esperava identificador");

	return false;
}

int estrutEnquanto() {
	if (estrutExpressao()) {
		if (token == TK_Faca) {
			leToken();
			if (estrutComandos()) {
				if (token == TK_FimEnquanto) {
					leToken();
					return true;
				}
				else
					erroS("Esperava fimenquanto");
			}
		}
		else
			erroS("Esperava .faca.");
	}
	return false;
}

int estrutRepita() {
	if (estrutComandos()) {
		if (token == TK_Ate) {
			leToken();
			if (estrutExpressao()) {
				return true;
			}
		}
		else
			erroS("Esperava token .ate.");
	}
	return false;
}

int estrutLeitura() {
	if (token == TK_Abre_par) {
		leToken();
		if (estrutListaVar()) {
			if (token == TK_Fecha_par) {
				leToken();
				return true;
			}
			else
				erroS("Esperava fecha parenteses");
		}
	}
	else
		erroS("Esperava abre parenteses");

	return false;
}

int estrutEscreva() {
	if (token == TK_Abre_par) {
		leToken();
		if (estrutListaExpressao()) {
			if (token == TK_Fecha_par) {
				leToken();
				return true;
			}
			else
				erroS("Esperava fecha parenteses");
		}
	}
	else
		erroS("Esperava abre parenteses");
	return false;
}

int estrutSe() {
	if (estrutExpressao()) {
		if (token == TK_Entao) {
			leToken();
			if (estrutComandos()) {
				if (estrutSe1()) {
					if (token == TK_Fimse) {
						leToken();
						return true;
					}
					else
						erroS("Esperava fimse");
				}
			}
		}
		else
			erroS("Esperava entao");
	}
	return false;
}

int estrutSe1() {
	if (token == TK_Senao) {
		leToken();
		if (estrutComandos()) {
				return true;
		}
	}
	return true;
}

int estrutAtribuicao() {
	if (token == TK_Atrib) { //Bloco ATRIBUICAO
		leToken();
		if ( estrutExpressao() ) {
			return true;
		}
	}

	return false;
}

int estrutListaExpressao() {
	if (estrutExpressao()) {
		if (token == TK_Virgula) {
			leToken();
			if (estrutListaExpressao()) {
				return true;
			}
		}
		return true;
	}
	return false;
}

int estrutOperador () {
	if ( (token == TK_Menos) || (token == TK_Potenciacao) || (token == TK_Mult) || (token == TK_Divide) || (token == TK_Resto) || (token == TK_Mais) || (token == TK_DivInt) )	{
		leToken();
		return true;
	}
	else
		return false;
}

int estrutOperadorRelacional() {
	if ( (token == TK_Igual) ||	 (token == TK_Diferente) || (token == TK_Maior) || (token == TK_Menor) || (token == TK_MaiorIgual) || (token == TK_MenorIgual) ) {
		leToken();
		return true;
	}
	else
		return false;
}

int estrutOperadorLogico() {
	if ( ( token == TK_E) || (token == TK_OU) ) {
		leToken();
		return true;
	}
	else
		    return false;
}

int estrutExpressao() {
	if ( estrutOperando() ){ //ARITMETICA, LOGICA, RELACIONAL
		if ( estrutOperadorLogico() ) { //EXP LOGICA
			if ( estrutExpressaoLogica() ) {
				return true;
			}
		}
		else if ( estrutOperador() ) {
			if ( estrutExpressaoArit() ){
				return true;
			}
		}
		else if ( estrutOperadorRelacional() ) {
			if ( estrutExpressaoRelacional() ){
				return true;
			}
		}
		return true; //somente ident ou const
	}
	else if ( ( token == TK_Menos ) ){ //ARITMETICA
		leToken();
		if (estrutExpressaoArit()) {
			return true;
		}
	}
	else if ( token == TK_String ){ //LITERAL
		leToken();
		if (estrutExpressaoLiteral()) {
			return true;
		}
	}
	else
	    return false;
}

int estrutExpressaoLogica() {
	if ( estrutExpressaoLogica1() ){
		if (estrutOperadorLogico()) {
			if (estrutExpressaoLogica()) {
				return true;
			}
		}
		else {
			return true;
		}
	}
	return false;
}

int estrutExpressaoLogica1() {
	if ( estrutOperando() ) {
		if ( estrutOperadorLogico() ) {
			if ( estrutExpressaoLogica1() ){
				return true;
			}
		}
		else if (estrutExpressaoRelacional()) {
			return true;
		}
		else
			return true;//somente constante
	}
	erroS("Não reconheceu exp. lógica");
	return false;
}

int estrutExpressaoArit() {
	if ( estrutExpressaoArit1() ) {
		if ( estrutOperador() ) {
			if ( estrutExpressaoArit() ){
				return true;
			}
		}
		else
			return true;//somente constante
	}
	else if (token == TK_Menos) {
		leToken();
		if (estrutExpressaoArit1()) {
			return true;
		}
	}
}

int estrutExpressaoArit1() {
	if ( estrutOperando() ) {
		if ( estrutOperador() ) {
			if ( estrutExpressaoArit1() ){
				return true;
			}
		}
		else
			return true;//somente constante
	}
}

int estrutIndiceVetor() {
  if (estrutOperando()) {
	  if (token == TK_FechaColchete) {
		  leToken();
		  if (token == TK_AbreColchete) {
			  leToken();
			  if (estrutIndiceVetor()) {
				  return true;
			  }
		  }
	  }
  }

}

int estrutOperando() {
	if ( (token == TK_Ident)) {
		leToken();
		if (token == TK_Abre_par) {
			leToken();
			if (estrutChamadaFuncao()) {
				return true;
			}
		}
		else if (token == TK_AbreColchete) {
			leToken();
			if (estrutIndiceVetor() ){
				return true;
			}
		}
		else
			return true;//somente ident ou const
	}
	else if ((token == TK_Const_int) || (token == TK_Const_real)) {
		leToken();
		return true;
	}
	else if ( (token == TK_Abs) || (token == TK_Raizq) || (token == TK_Sen) || (token == TK_Cos) || (token == TK_Int) ) {
		leToken();
		if (token == TK_Abre_par) {
			leToken();
			if ( estrutChamadaFuncao() ) {
					return true;
			}
		}
		else
		  erroS("Esperava abre parenteses");
		return false;
	}
	else if (token == TK_Abre_par) {
		leToken();
		if (estrutExpressao()) {
			if (token == TK_Fecha_par) {
				leToken();
				return true;
			}
			else
			    erroS("faltou fecha parenteses");
		}
	}

//    erroS("Nao reconheceu operando");
	return false;
}


int estrutExpressaoLiteral() {
	if (token == TK_Mais) {
		leToken();
		if (token == TK_String) {
			leToken();
			if ( estrutExpressaoLiteral() )
				return true;
		}
		if (token == TK_Ident) {
			leToken();
			if ( estrutExpressaoLiteral() )
				return true;
		}
	}
	return true;

}

int estrutExpressaoRelacional() {
	if ( estrutExpressaoRelacional1() ){
		if (estrutOperadorRelacional()) {
			if (estrutExpressaoRelacional()) {
				return true;
			}
		}
		else {
			return true;
		}
	}
//    erroS("Nao reconheceu expressao relacional");
	return false;
}

int estrutExpressaoRelacional1() {
	if ( estrutOperando() ) {
		if ( estrutOperadorRelacional() ) {
			if ( estrutExpressaoRelacional1() ){
				return true;
			}
		}
		else
			return true;//somente constante
	}
	return false;
}


int estrutChamadaFuncao() {
	if ( (token == TK_Ident) || (token == TK_Const_int) || (token == TK_Const_real) ) {
		leToken();
		if (estrutParametro()) {
			if (token == TK_Fecha_par) {
			  leToken();
			  return true;
			}
		}
	}
	else if ( estrutExpressao() ) {
		if (token == TK_Fecha_par) {
		  leToken();
		  return true;
		}
	}
	else
		if (token == TK_Fecha_par) {
		  leToken();
  		return true; //Não é obrig. a ter parametros.
		}
	return false;
}

int estrutParametro() {
	if (estrutParametro1() ) {
		return true;
	}
	return true;
}

int estrutParametro1() {
	if (token == TK_Virgula) {
		leToken();
		if (estrutParametro() ) {
			return true;
		}
		else
			erroS("Esperava parametro");
	}
	return true;
}

int estrutParametrosFormais() {
	if (token == TK_Var) {
		leToken();
		if (estrutListaDecl()) {
			return true;
		}

	}
	else if (estrutListaDecl()) {
		if (estrutListaDecl()) {
			return true;
		}
	}
	return true;

}


int estrutRetorno() {
	if ( estrutTipo() ){
		return true;
	}
	else {
        erroS("Tipo de retorno inválido!");
		return false;
	}
}



//Sintático
int verifGramatica() {

	leToken();

	if (token == TK_Algoritmo) { //Algoritmo
		leToken();
		if (token == TK_Ident) //NOme algoritmo
			leToken();

		//Com declaração de variáveis
		if (token == TK_Var) {
			leToken();
			if ( estrutVar() ) {
				if (token == TK_Inicio) {
					leToken();
					if (estrutBloco() ) {
						if (token == TK_Fim_Alg) {
							leToken();
							return true;
						}
						else
							erroS("Esperava fimalgoritmo");

					}
				}
			}
		}
		//Sem declaração de variáveis
		if (token == TK_Inicio) {
			leToken();
			if (estrutBloco() ) {
				if (token == TK_Fim_Alg) {
					//FINAL
					return true;
				}
			}
		}

	}
	else
		erroS("Deve comecar  com token .algoritmo.");


	return 0;
}

//Somente Léxico
void verifTokens() {

	while ((ct_tk < tamanho_expressao))
		leToken();

}

int leArquivo() {

	if (!feof(arqF))
	{
      fgets(expressao, 500, arqF);
  	  tamanho_expressao = strlen(expressao) + 1;
  	  ct_tk = 0;
  	  token = 0;
  	  linha++;
	}
	else
  	  return 0;


	return 1;

}

int abreArquivoFonte(){
	if((arqF = fopen(nomearq_fonte, "r")) == NULL)
		return 0;
	return 1;
}

void fechaArquivoFonte() {
	fclose(arqF);
}

int abreArquivoToken(){
	if((arqTk = fopen(nomearq_token, "a+")) == NULL)
		return 0;
	return 1;
}

void fechaArquivoToken() {
	fclose(arqTk);
}


int main(int argc, char *argv[])
{

	printf("Analisador Lexico e Sintatico\n");
	printf("Arquivo de Entrada: [DIRETORIO_CORRENTE]/ENTRADA.ALG \n");
	printf(" \n");
	printf("Menu \n");
	printf("[enter] para Analisador Lexico e Sintatico \n");

	//getch();


	if (abreArquivoFonte()) {


		if (verifGramatica())
			printf("\n\nO código foi reconhecido com sucesso...\n\n");

	}
	else
		printf("Arquivo fonte nao encontrado\n");

//	system("Pause");
	return true;


}




