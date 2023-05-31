#include "ExpressaoSubtracao.hpp"
#include <iostream>
#include "ExpressaoFloat.hpp"
#include "ExpressaoNumero.hpp"
#include "../debug-util.hpp"

using namespace std;
ExpressaoSubtracao::ExpressaoSubtracao() { }

tuple<Tipo, int, float, bool> ExpressaoSubtracao::avalia(stack<Tabela *> &pilha_de_tabelas)
{
  tuple<Tipo, int, float, bool> resultado;

  // Avalia a expressão da esquerda
  auto esq = esquerda->avalia(pilha_de_tabelas);

  // Avalia a expressão da direita
  auto dir = direita->avalia(pilha_de_tabelas);

  // Se os dois operandos forem inteiros
  if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER)
  {
    int sub = get<1>(esq) - get<1>(dir);
    resultado = make_tuple(Tipo::INTEGER, sub, 0.0f, false);
  }
  else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT)
  {
    float sub = get<2>(esq) - get<2>(dir);
    resultado = make_tuple(Tipo::FLOAT, 0, sub, false);
  }
  // Se algum operando for bool
  else if (get<0>(esq) == Tipo::BOOL || get<0>(dir) == Tipo::BOOL)
  {
    throw runtime_error("Erro: Expressao subtracao com bool");
  }
  else{
    throw runtime_error("Erro: Expressao subtracao com tipos incompativeis");
  }
  return resultado;
}


void ExpressaoSubtracao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "- [ INI Subtracao"<< endl;
  esquerda->debug_com_tab(tab-1);
  tab3(tab);
  cerr << "-" << endl;
  direita->debug_com_tab(tab-1);
  tab3(tab);
  cerr << "- ] FIM Subtracao"<< endl;
}
