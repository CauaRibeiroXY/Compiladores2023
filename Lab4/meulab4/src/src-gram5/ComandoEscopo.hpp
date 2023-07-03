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
      virtual void var_in_frame( vector<string> &var_frame);
  virtual void percurso_funcao(  map < string, FrameAcesso* > &table );
};

#endif // COMANDO_ESCOPO_HPP
