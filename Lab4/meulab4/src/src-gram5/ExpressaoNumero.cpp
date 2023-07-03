#include "ExpressaoNumero.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoNumero::ExpressaoNumero() { }

tuple<Tipo, int, float, bool> ExpressaoNumero::avalia(stack<Tabela*> &stack_symbol_table){
  if (numero == nullptr) {
    throw runtime_error("Erro: ExpressaoFloat com ponteiro nulo.");
  }
  return make_tuple(Tipo::INTEGER, numero->valor, 0.0f, false);
}

// Expressao* ExpressaoNumero::avalia(stack<Tabela*>& pilha_de_tabelas) {
//   return this;
// }

void ExpressaoNumero::var_in_frame( vector<string> &var_frame, bool chamada){

}

void ExpressaoNumero::percurso_funcao(  map < string, FrameAcesso* > &table ){

}

void ExpressaoNumero::debug_com_tab(int tab) {
  tab3(tab);
  cerr << numero->valor << " [Numero]"<< endl;
}
