#ifndef cabecalho_hpp
#define cabecalho_hpp

//BIBLIOTECAS
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include <windows.h>

//DEFINICAO DE CONSTANTES
#define ITENSPAGINA 4
#define MAXTABELA 100
#define MAX 1000
#define M 4
#define MM (M*2)
#define PAGES 200

//ESTRUTURA DE INDICES P/ PESQUISA SEQUENCIAL
typedef struct {
	int chave;
	int posicao;
}indice;

//ESTRUTURA DE ARQUIVO DE ENTRADA
typedef struct {
	int chave;
	long int dado1;
	char dado2[MAX];
}Titem;

//ESTRUTURA P/ ARVORE BINARIA DE PESQUISA EM MEMORIA EXTERNA
typedef struct {
	int chave;
	long int dado1;
	char dado2[MAX];
	int pDir, pEsq;
}Titem2;


//ESTRUTURAS PARA ARVORE B DE ORDEM M
typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
	short n;
	Titem r[MM];
	TipoApontador p[MM + 1];
} TipoPagina;

//ESTRUTURAS PARA ARVORE B* DE ORDEM M
typedef long TipoChave;
typedef struct TipoRegistro {
TipoChave Chave;
} TipoRegistro;

typedef enum {Int, Ext} TipoIntExt;
typedef struct TipoPagina* TipoApontador;
typedef struct TipoPagina {
TipoIntExt Pt;
union {
struct {
int ni;
TipoChave ri[MM];
TipoApontador pi[MM + 1];
} U0;
struct {
int ne;
TipoRegistro re[MM2];
} U1;
} UU;
} TipoPagina;

//FUNCOES P/ PESQUISA SEQUENCIAL INDEXADA:
int pesquisa_Sequencial (indice tab[], int tam, Titem* item, FILE *arq);
int acesso_sequencial(FILE* arq, int chave, int tamanho);


//FUNCOES P/ ARVORE BINARIA DE PESQUISA EXTERNA
int Arvore_Binaria_Memoria_Externa(void);
void pesquisa(int chave);


//FUNCOES P/ ARVORE B
void pesquisa_ArvoreB(int chave);
void Inicializa(TipoApontador * );
void Insere(Titem, TipoApontador *, int);
void Ins(Titem, TipoApontador, short *, Titem *,  TipoApontador *, int);
void InsereNaPagina(TipoApontador, Titem , TipoApontador, int);
void Pesquisa_AB(Titem *, TipoApontador, int, int);


//GERADOR DE ARQUIVOS BINARIOS:
int gerador(int num, int opcao, int arg);

#endif
