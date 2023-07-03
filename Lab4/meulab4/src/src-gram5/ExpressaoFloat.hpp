#ifndef _EXPRESSAOFLOAT_HPP_
#define _EXPRESSAOFLOAT_HPP_
#include "Expressao.hpp"
#include "FLOAT.hpp"
using namespace std;

class ExpressaoFloat : public Expressao
{
public:
  FLOAT *numero;
  ExpressaoFloat();
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
  void percurso_funcao(  map < string, FrameAcesso* > &table );
  void var_in_frame( vector<string> &var_frame, bool chamada);
  void debug_com_tab(int tab);
};

#endif