#ifndef _EXPRESSAO_MOD_HPP_
#define _EXPRESSAO_MOD_HPP_
#include "Expressao.hpp"

using namespace std;

class ExpressaoMod : public Expressao
{
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoMod();
  virtual tuple<Tipo, int, float, bool> avalia(stack<Tabela *> &pilha_de_tabelas);
  void percurso_funcao(map<string, FrameAcesso *> &table);
  void var_in_frame(vector<string> &var_frame, bool chamada);
  void debug_com_tab(int tab);
};

#endif
