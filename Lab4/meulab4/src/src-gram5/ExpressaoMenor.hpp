#ifndef _ExpressaoMenor_HPP_
#define _ExpressaoMenor_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoMenor : public Expressao {
    public:
        Expressao* esquerda;
        Expressao* direita;
        ExpressaoMenor();
          virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);
        void debug_com_tab(int tab);
};

#endif