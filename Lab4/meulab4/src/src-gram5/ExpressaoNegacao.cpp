#include "ExpressaoNegacao.hpp"
#include "Expressao.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ExpressaoNegacao::ExpressaoNegacao() {}

tuple<Tipo, int, float, bool> ExpressaoNegacao::avalia(stack<Tabela*> &pilha_de_tabelas) {
  auto dir = direita->avalia(pilha_de_tabelas);
  
  if (get<0>(dir) == Tipo::BOOL) {
    bool resultado = !get<3>(dir);
    return make_tuple(Tipo::BOOL, 0, 0.0f, resultado);
  }
  
  throw runtime_error("Erro: ExpressaoNegacao com tipo incompatível.");
}

void ExpressaoNegacao::var_in_frame( vector<string> &var_frame, bool chamada){
  direita->var_in_frame(var_frame, false);
}

void ExpressaoNegacao::percurso_funcao(  map < string, FrameAcesso* > &table ){
  direita->percurso_funcao(table);
}

void ExpressaoNegacao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "! [ INI Negacao"<< endl;
  direita->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "! ] FIM Negacao"<< endl;
}
