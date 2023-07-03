#ifndef _EXPRESSAO_NUMERO_HPP_
#define _EXPRESSAO_NUMERO_HPP_
#include "Expressao.hpp"
#include "INTEGER.hpp"
using namespace std;

class ExpressaoNumero : public Expressao {
public:
  INTEGER* numero;
  ExpressaoNumero();
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
    void percurso_funcao(  map < string, FrameAcesso* > &table );
  void var_in_frame( vector<string> &var_frame, bool chamada);
  void debug_com_tab(int tab);
};

#endif
