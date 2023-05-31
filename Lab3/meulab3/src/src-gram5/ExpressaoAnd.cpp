#include "ExpressaoAnd.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoAnd::ExpressaoAnd() {}

tuple<Tipo, int, float, bool> ExpressaoAnd::avalia(stack<Tabela*> &pilha_de_tabelas) {
  auto esq = esquerda->avalia(pilha_de_tabelas);
  auto dir = direita->avalia(pilha_de_tabelas);
  
  if (get<0>(esq) == Tipo::BOOL && get<0>(dir) == Tipo::BOOL) {
    bool resultado = (get<3>(esq) && get<3>(dir));
    return make_tuple(Tipo::BOOL, 0, 0.0f, resultado);
  }
  else {
    throw runtime_error("Erro: ExpressaoAnd com tipos incompatíveis.");
  }
}


void ExpressaoAnd::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "And [ INI And"<< endl;
    esquerda->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "And" << endl;
    direita->debug_com_tab(tab+1);
    tab3(tab);
    cerr << "And ] FIM And"<< endl;
}
