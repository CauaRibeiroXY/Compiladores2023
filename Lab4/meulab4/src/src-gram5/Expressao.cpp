#include "Expressao.hpp"
#include "ExpressaoDivisao.hpp"
#include "ExpressaoMod.hpp"
#include "ExpressaoMultiplicacao.hpp"
#include "ExpressaoNumero.hpp"
#include "ExpressaoFloat.hpp"
#include "ExpressaoBool.hpp"
#include "ExpressaoSoma.hpp"
#include "ExpressaoSubtracao.hpp"
#include "ExpressaoVariavel.hpp"
#include "ExpressaoIgual.hpp"
#include "ExpressaoMenor.hpp"
#include "ExpressaoAnd.hpp"
#include "ExpressaoOr.hpp"
#include "ExpressaoNegacao.hpp"
#include "ExpressaoChamada.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

// Tratei tanto o EXPRESSION_ART,COMP,LOGIC quanto TERM e FACTOR na mesma funcao.
Expressao *Expressao::extrai_expressao(No_arv_parse *no)
{
  // 23) a 48)
  switch (no->regra)
  {
  case 23:
  { // 26) EXPRESSION_ART -> EXPRESSION_ART + TERM
    cout << "Soma" << endl;
    ExpressaoSoma *res23 = new ExpressaoSoma();
    res23->esquerda = extrai_expressao(no->filhos[0]);
    res23->direita = extrai_expressao(no->filhos[2]);
    return res23;
  }
  case 24:
  { // 27) EXPRESSION_ART -> EXPRESSION_ART - TERM
    ExpressaoSubtracao *res24 = new ExpressaoSubtracao();
    res24->esquerda = extrai_expressao(no->filhos[0]);
    res24->direita = extrai_expressao(no->filhos[2]);
    return res24;
  }
  case 25:
  { // 25) EXPRESSION_ART -> TERM
    cout << "Term" << endl;
    return extrai_expressao(no->filhos[0]);
  }
  case 27:
  { // 27) TERM -> TERM * FACTOR
    ExpressaoMultiplicacao *res27 = new ExpressaoMultiplicacao();
    res27->esquerda = extrai_expressao(no->filhos[0]);
    res27->direita = extrai_expressao(no->filhos[2]);
    return res27;
  }
  case 28:
  { // 28) TERM -> TERM / FACTOR
    ExpressaoDivisao *res28 = new ExpressaoDivisao();
    res28->esquerda = extrai_expressao(no->filhos[0]);
    res28->direita = extrai_expressao(no->filhos[2]);
    return res28;
  }
  case 29:
  { // 29) TERM -> TERM % FACTOR
    ExpressaoMod *res29 = new ExpressaoMod();
    res29->esquerda = extrai_expressao(no->filhos[0]);
    res29->direita = extrai_expressao(no->filhos[2]);
    return res29;
  }
  case 26:
  { // 26) TERM -> FACTOR
    cout << "Factor" << endl;
    return extrai_expressao(no->filhos[0]);
  }
  case 31:
  { // 31) FACTOR -> KW_TRUE
    ExpressaoBool *res31 = new ExpressaoBool();
    res31->booleano = BOOL::extrai_BOOL(no->filhos[0]);
    return res31;
  }
  case 32:
  { // 32) FACTOR -> KW_FALSE
    ExpressaoBool *res32 = new ExpressaoBool();
    res32->booleano = BOOL::extrai_BOOL(no->filhos[0]);
    return res32;
  }
  case 33:
  { // 33) FACTOR -> - INTEGER_LITERAL
    ExpressaoNumero *res33 = new ExpressaoNumero();
    res33->numero = INTEGER::extrai_INTEGER(no->filhos[0], false);
    return res33;
  }
  case 34:
  { // 34) FACTOR -> - FLOAT_LITERAL
    ExpressaoFloat *res34 = new ExpressaoFloat();
    res34->numero = FLOAT::extrai_FLOAT(no->filhos[0], false);
    return res34;
  }
  case 35:
  { // 35) FACTOR -> IDENTIFIER
    ExpressaoVariavel *res35 = new ExpressaoVariavel();
    res35->nome = ID::extrai_ID(no->filhos[0]);
    return res35;
  }
  case 36:
  { // 36) FACTOR -> INTEGER_LITERAL

    ExpressaoNumero *res = new ExpressaoNumero();
    res->numero = INTEGER::extrai_INTEGER(no->filhos[0]);
    cout << "Numero " << endl;
    return res;
  }
  case 37:
  { // 37) FACTOR -> FLOAT_LITERAL
    ExpressaoFloat *res = new ExpressaoFloat();
    res->numero = FLOAT::extrai_FLOAT(no->filhos[0]);
    cout << "Numero " << endl;
    return res;
  }
  case 38:
  { // 38) FACTOR -> ( EXPRESSION_LOGICA )
    return extrai_expressao(no->filhos[1]);
  }
  case 39:
  { // 39)EXPRESSION_COMP -> EXPRESSION_ART == EXPRESSION_ART
    ExpressaoIgual *res = new ExpressaoIgual();
    res->esquerda = extrai_expressao(no->filhos[0]);
    res->direita = extrai_expressao(no->filhos[2]);
    return res;
  }
  case 40:
  { // 40)EXPRESSION_COMP -> EXPRESSION_ART < EXPRESSION_ART
    ExpressaoMenor *res = new ExpressaoMenor();
    res->esquerda = extrai_expressao(no->filhos[0]);
    res->direita = extrai_expressao(no->filhos[2]);
    return res;
  }
  case 41:
  { // 41) EXPRESSION_COMP -> EXPRESSION_ART

    return extrai_expressao(no->filhos[0]);
  }
  case 42:
  { // 42) EXPRESSION_LOGICA && EXPRESSION_COMP
    ExpressaoAnd *res = new ExpressaoAnd();
    res->esquerda = extrai_expressao(no->filhos[0]);
    res->direita = extrai_expressao(no->filhos[2]);
    return res;
  }
  case 43:
  { // 43) EXPRESSION_LOGICA -> EXPRESSION_LOGICA || EXPRESSION_COMP
    ExpressaoOr *res = new ExpressaoOr();
    res->esquerda = extrai_expressao(no->filhos[0]);
    res->direita = extrai_expressao(no->filhos[2]);
    return res;
  }
  case 44:
  { // 44) EXPRESSION_LOGICA -> ! EXPRESSION_COMP
    ExpressaoNegacao *res = new ExpressaoNegacao();
    res->direita = extrai_expressao(no->filhos[1]);
    return res;
  }
  case 45:
  { // 45) EXPRESSION_LOGICA -> EXPRESSION_COMP

    return extrai_expressao(no->filhos[0]);
  }
  case 30:
  { //FACTOR -> CALL_FUNCTION
    ExpressaoChamada *res = new ExpressaoChamada();
    res->nome_funcao = ID::extrai_ID(no->filhos[0]->filhos[0]);
    res->argumentos = ExpressaoChamada::extrai_lista_expressoes_parametro(no->filhos[0]->filhos[2]);
    return res;
  }
  default:
  {
    return NULL;
  }
  }
}

tuple<Tipo, int, float, bool> Expressao::avalia(stack<Tabela *> &pilha_de_tabelas)
{
  return make_tuple(Tipo::INTEGER, 0, 0, false);
}

void Expressao::var_in_frame( vector<string> &var_frame, bool chamada){

}

void Expressao::percurso_funcao( map < string, FrameAcesso* > &table ){
  
}

void Expressao::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "Expressao generica" << endl;
}
