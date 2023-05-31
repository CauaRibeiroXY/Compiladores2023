#include "ExpressaoIgual.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ExpressaoIgual::ExpressaoIgual() {}

tuple<Tipo, int, float, bool> ExpressaoIgual::avalia(stack<Tabela*> &pilha_de_tabelas) {
  auto esq = esquerda->avalia(pilha_de_tabelas);
  auto dir = direita->avalia(pilha_de_tabelas);
  
  if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER) {
    bool resultado = (get<1>(esq) == get<1>(dir));
    return make_tuple(Tipo::BOOL, 0, 0.0f, resultado);
  }
  else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT) {
    bool resultado = (get<2>(esq) == get<2>(dir));
    return make_tuple(Tipo::BOOL, 0, 0.0f, resultado);
  }
  else {
    throw runtime_error("Erro: ExpressaoIgual com tipos incompatíveis.");
  }
}


void ExpressaoIgual::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "Igual [ INI Igual"<< endl;
    esquerda->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "Igual" << endl;
    direita->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "Igual ] FIM Igual"<< endl;
}
