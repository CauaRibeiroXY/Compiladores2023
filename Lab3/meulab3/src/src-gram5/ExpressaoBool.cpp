#include "ExpressaoBool.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoBool::ExpressaoBool() { }

tuple<Tipo, int, float, bool> ExpressaoBool::avalia(stack<Tabela*> &pilha_de_tabelas) {
  // Verifica se o ponteiro booleano está válido
  if (booleano == nullptr) {
    throw runtime_error("Erro: ExpressaoBool com ponteiro nulo.");
  }

  // Retorna o valor booleano armazenado no ponteiro
  return make_tuple(Tipo::BOOL, 0, 0.0f, booleano->valor);
}

void ExpressaoBool::debug_com_tab(int tab) {
  tab3(tab);
  cerr << booleano->valor << " [Numero]"<< endl;
}
