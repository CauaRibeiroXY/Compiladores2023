#ifndef _COMANDO_HPP_
#define _COMANDO_HPP_
#include <vector>
#include <stack>
#include <iostream>
#include <tuple>
#include "Tabela.hpp"
#include "../Frame/FrameAcesso.hpp"
#include "../Arvore.hpp"

using namespace std;



class Comando {
public:
  
  static vector<Comando*> extrai_lista_comandos(No_arv_parse* no);
  static Comando* extrai_comando(No_arv_parse* no);
  virtual void debug_com_tab(int tab);
  virtual tuple<Tipo,int,float,bool> avalia_comando(stack<Tabela*> &simbolos);

  virtual void var_in_frame( vector<string> &var_frame);
  virtual void percurso_funcao(  map < string, FrameAcesso* > &table );

};

#endif
