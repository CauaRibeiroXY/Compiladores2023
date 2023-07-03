#ifndef _ExpressaoOr_HPP_
#define _ExpressaoOr_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoOr : public Expressao {
    public:
    Expressao* esquerda;
    Expressao* direita;
    ExpressaoOr();
      virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
    void debug_com_tab(int tab);
};

#endif