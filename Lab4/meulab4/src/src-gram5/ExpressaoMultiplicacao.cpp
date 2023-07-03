#include "ExpressaoMultiplicacao.hpp"
#include <iostream>
#include "ExpressaoNumero.hpp"
#include "ExpressaoFloat.hpp"
#include "../debug-util.hpp"

using namespace std;

ExpressaoMultiplicacao::ExpressaoMultiplicacao() { }
tuple<Tipo, int, float, bool> ExpressaoMultiplicacao::avalia(stack<Tabela*> &pilha_de_tabelas) {
  tuple<Tipo, int, float, bool> resultado;

  // Avalia a expressão da esquerda
  auto esq = esquerda->avalia(pilha_de_tabelas);

  // Avalia a expressão da direita
  auto dir = direita->avalia(pilha_de_tabelas);

  // Se os dois operandos forem inteiros
  if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER)
  {
    int mult = get<1>(esq) * get<1>(dir);
    resultado = make_tuple(Tipo::INTEGER, mult, 0.0f, false);
  }
  else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT)
  {
    float mult = get<2>(esq) * get<2>(dir);
    resultado = make_tuple(Tipo::FLOAT, 0, mult, false);
  }
  // Se algum operando for bool
  else if (get<0>(esq) == Tipo::BOOL || get<0>(dir) == Tipo::BOOL)
  {
    throw runtime_error("Erro: Expressao multiplicacao com bool");
  }
  else{
    throw runtime_error("Erro: Expressao multiplicacao com tipos incompativeis");
  }
  return resultado;
}

void ExpressaoMultiplicacao::var_in_frame( vector<string> &var_frame, bool chamada){
  esquerda->var_in_frame(var_frame, false);
  direita->var_in_frame(var_frame, false);
}

void ExpressaoMultiplicacao::percurso_funcao(  map < string, FrameAcesso* > &table ){
  esquerda->percurso_funcao(table);
  direita->percurso_funcao(table);
}

void ExpressaoMultiplicacao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "* [ INI Multiplicacao"<< endl;
  esquerda->debug_com_tab(tab*1);
  tab3(tab);
  cerr << "*" << endl;
  direita->debug_com_tab(tab*1);
  tab3(tab);
  cerr << "* ] FIM Multiplicao"<< endl;
}
