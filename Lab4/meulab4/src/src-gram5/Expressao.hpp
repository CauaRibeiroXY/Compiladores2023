#ifndef _EXPRESSAO_HPP_
#define _EXPRESSAO_HPP_
#include "../Arvore.hpp"
#include "Tabela.hpp"
#include "../Frame/FrameAcesso.hpp"
#include "../Frame/FrameAcessoTemp.hpp"
#include <stdexcept>
#include <stack>
using namespace std;

class Expressao {
public:
  static Expressao* extrai_expressao(No_arv_parse* no);
  virtual tuple<Tipo, int, float, bool> avalia(stack <Tabela*> & pilha_de_tabelas);

  virtual void percurso_funcao( map < string, FrameAcesso* > &table );

  virtual void var_in_frame(vector<string> &var_frame, bool chamada);

  virtual void debug_com_tab(int tab);
};

#endif
