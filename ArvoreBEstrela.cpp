#include "cabecalho.hpp"

using namespace std;

void Pesquisa(TipoRegistro *x, TipoApontador *Ap)
{int i;
TipoApontador arvore;
arvore = *Ap; 
if ((*Ap)->Pt == Int)
{ i = 1;
//PESQUISA SEQUENCIAL EM PAGINA INTERNA
while(i < arvore->UU.UO.ni && x->chave > arvore->UU.UO.ri[i-1])i++;
if(x->chave < arvore->UU.UO.ri[i-1])
Pesquisa(x, &arvore->UU.UO.pi[i-1]);
//ATIVAÇAO DE PESQUISA SOMENTE EM PAGINAS-FOLHA
else Pesquisa(x, &arvore->UU.UO.pi[i]);
return;
}
i=1;
while(i<arvore->UU.U1.ne && x->chave > arvore->UU.U1.re[i-1].chave)
i++;
if (x->chave==arvore->UU.U1.re[i-1].chave)
*x = arvore->UU.U1.re[i-1];
return 1;
}