#ifndef _EXPRESSAO_MULTIPLICACAO_HPP_
#define _EXPRESSAO_MULTIPLICACAO_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoMultiplicacao : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
    virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
  ExpressaoMultiplicacao();
  void percurso_funcao(  map < string, FrameAcesso* > &table );
  void var_in_frame( vector<string> &var_frame, bool chamada);
  void debug_com_tab(int tab);
};

#endif
