#ifndef _EXPRESSAO_DIVISAO_HPP_
#define _EXPRESSAO_DIVISAO_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoDivisao : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoDivisao();
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
  void debug_com_tab(int tab);
};

#endif
