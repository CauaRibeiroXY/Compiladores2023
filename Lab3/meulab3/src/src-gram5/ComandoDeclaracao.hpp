#ifndef _COMANDO_DECLARACAO_HPP_
#define _COMANDO_DECLARACAO_HPP_
#include "Comando.hpp"
#include "Variavel.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
using namespace std;

class ComandoDeclaracao : public Comando
{
public:
  Variavel *variavel;
  Expressao *expressao;
  ComandoDeclaracao();
  virtual tuple<Tipo, int, float, bool> avalia_comando(stack<Tabela *> &pilha_de_tabelas);
  void debug_com_tab(int tab);
};
#endif