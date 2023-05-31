#ifndef _EXPRESSAO_HPP_
#define _EXPRESSAO_HPP_
#include "../Arvore.hpp"
#include "Tabela.hpp"
#include <stack>
using namespace std;

class Expressao {
public:
  static Expressao* extrai_expressao(No_arv_parse* no);
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
  virtual void debug_com_tab(int tab);
};

#endif
