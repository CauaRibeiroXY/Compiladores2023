#ifndef _ExpressaoNegacao_HPP_
#define _ExpressaoNegacao_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoNegacao : public Expressao {
    public:
    Expressao* direita;
    ExpressaoNegacao();
    virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
    void percurso_funcao(  map < string, FrameAcesso* > &table );
  void var_in_frame( vector<string> &var_frame, bool chamada);
    void debug_com_tab(int tab);
};

#endif
