#ifndef _ExpressaoBool_HPP_
#define _ExpressaoBool_HPP_
#include "Expressao.hpp"
#include "BOOL.hpp"

using namespace std;

class ExpressaoBool : public Expressao{
public:
  BOOL* booleano;
  ExpressaoBool();
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
  void debug_com_tab(int tab);
};

#endif
