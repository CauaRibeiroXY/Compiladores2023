#ifndef _ANALISADOR_HPP_
#define _ANALISADOR_HPP_
#include "Funcao.hpp"
#include "Comando.hpp"
#include <string>
#include <vector>
#include <stack>
#include "Tabela.hpp"
#include <iostream>

using namespace std;

class Analisador {
public:
  stack<Tabela*> pilha_de_tabelas;
  Analisador();

 string calcula_ultimo_valor(Funcao* f, const vector<tuple<Tipo, int, float, bool>>& params);

};
  
#endif
