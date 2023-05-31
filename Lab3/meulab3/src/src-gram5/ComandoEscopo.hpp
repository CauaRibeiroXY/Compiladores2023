#ifndef _COMANDO_ESCOPO_HPP
#define _COMANDO_ESCOPO_HPP
#include "Comando.hpp"
#include "Tabela.hpp"
#include <stack>

class ComandoEscopo : public Comando
{
public:
    vector<Comando *> comandos;

    tuple<Tipo, int, float, bool> avalia_comando(stack<Tabela *> &pilha_de_tabelas);
};

#endif // COMANDO_ESCOPO_HPP
