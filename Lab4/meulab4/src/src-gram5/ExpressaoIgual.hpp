#ifndef _ExpressaoIgual_HPP_
#define _ExpressaoIgual_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoIgual : public Expressao {
    public:
        Expressao* esquerda;
        Expressao* direita;
        ExpressaoIgual();
          virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
        void debug_com_tab(int tab);
};

#endif