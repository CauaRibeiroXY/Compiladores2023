#include "ExpressaoFloat.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoFloat::ExpressaoFloat() { }

tuple<Tipo, int, float, bool> ExpressaoFloat::avalia(stack<Tabela*> &stack_symbol_table) {
  if (numero == nullptr) {
    throw runtime_error("Erro: ExpressaoFloat com ponteiro nulo.");
  }
  return make_tuple(Tipo::FLOAT, 0, numero->valor, false);
}



void ExpressaoFloat::debug_com_tab(int tab) {
  tab3(tab);
  cerr << numero->valor << " [Numero]"<< endl;
}
