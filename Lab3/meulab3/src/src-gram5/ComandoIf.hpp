#ifndef _ComandoIf_HPP_
#define _ComandoIf_HPP_
#include "Comando.hpp"
#include "Expressao.hpp"

using namespace std;

class ComandoIf : public Comando
{
    public:
        Expressao *expressao;
        vector<Comando*> comando;
        vector<Comando*> comando_else;
        ComandoIf();
        virtual tuple<Tipo, int, float, bool> avalia_comando(stack<Tabela *> &pilha_de_tabelas);
        
};

#endif