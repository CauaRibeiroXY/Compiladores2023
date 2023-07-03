#ifndef _COMANDO_ATRIBUI_HPP_
#define _COMANDO_ATRIBUI_HPP_
#include "Comando.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
#include "../Frame/FrameAcessoTemp.hpp"
using namespace std;

class ComandoAtribuicao : public Comando
{
public:
  ID *esquerda;
  Expressao *direita;
  ComandoAtribuicao();
  void debug_com_tab(int tab);
  virtual tuple<Tipo, int, float, bool> avalia_comando(stack<Tabela *> &simbolos);
  void percurso_funcao(map<string, FrameAcesso *> &table);
  void var_in_frame(vector<string> &var_frame);
};

#endif
