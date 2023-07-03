#ifndef _EXPRESSAO_VARIAVEL_HPP_
#define _EXPRESSAO_VARIAVEL_HPP_
#include "Expressao.hpp"
#include "ID.hpp"
using namespace std;

class ExpressaoVariavel : public Expressao
{
public:
  ID *nome;
  FrameAcesso *acesso_frame;
  ExpressaoVariavel();
  virtual tuple<Tipo, int, float, bool> avalia(stack<Tabela *> &pilha_de_tabelas);
  void percurso_funcao(map<string, FrameAcesso *> &table);
  void var_in_frame(vector<string> &var_frame, bool chamada);
  void debug_com_tab(int tab);
};

#endif
