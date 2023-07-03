#include "ExpressaoOr.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoOr::ExpressaoOr() {}

tuple<Tipo, int, float, bool> ExpressaoOr::avalia(stack<Tabela*> &pilha_de_tabelas) {
  auto esq = esquerda->avalia(pilha_de_tabelas);
  auto dir = direita->avalia(pilha_de_tabelas);
  
  if (get<0>(esq) == Tipo::BOOL && get<0>(dir) == Tipo::BOOL) {
    bool resultado = get<3>(esq) || get<3>(dir);
    return make_tuple(Tipo::BOOL, 0, 0.0f, resultado);
  }
  
  throw runtime_error("Erro: ExpressaoOr com tipos incompatíveis.");
}


void ExpressaoOr::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "Or [ INI Or"<< endl;
    esquerda->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "Or" << endl;
    direita->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "Or ] FIM Or"<< endl;
}
