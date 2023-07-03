#include "ExpressaoDivisao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoDivisao::ExpressaoDivisao() { }
tuple<Tipo, int, float, bool> ExpressaoDivisao::avalia(stack<Tabela*> &pilha_de_tabelas) {
  tuple<Tipo, int, float, bool> resultado;
    
  // Avalia a expressão da esquerda
  auto esq = esquerda->avalia(pilha_de_tabelas);
    
  // Avalia a expressão da direita
  auto dir = direita->avalia(pilha_de_tabelas);

  // Se os dois operandos forem inteiros
  if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER) {
    int divisor = get<1>(dir);
    if (divisor != 0) {
      int div = get<1>(esq) / divisor;
      resultado = make_tuple(Tipo::INTEGER, div, 0.0f, false);
    } else {
      throw runtime_error("Erro: Divisão por zero");
    }
  }
   // Se os dois operandos forem float
  else if ((get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT) && (get<0>(esq) != Tipo::BOOL && get<0>(dir) != Tipo::BOOL)) {
    float divisor = get<2>(dir);
    if (divisor != 0.0f) {
      float div = get<2>(esq) / divisor;
      resultado = make_tuple(Tipo::FLOAT, 0, div, false);
    } else {
      throw runtime_error("Erro: Divisão por zero");
    }
  }
  // Se algum operando for bool
  else if (get<0>(esq) == Tipo::BOOL || get<0>(dir) == Tipo::BOOL) {
    throw runtime_error("Erro: Expressão de divisão com tipo bool");
  }
  else{
    throw runtime_error("Erro: Expressão de divisão com tipos incompatíveis");
  }
  
  return resultado;
}
void ExpressaoDivisao::var_in_frame( vector<string> &var_frame, bool chamada){
  direita->var_in_frame(var_frame, false);
  esquerda->var_in_frame(var_frame, false);
}

void ExpressaoDivisao::percurso_funcao(  map < string, FrameAcesso* > &table ){
  esquerda->percurso_funcao(table);
  direita->percurso_funcao(table);
}

void ExpressaoDivisao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "/ [ INI Divisao"<< endl;
  esquerda->debug_com_tab(tab/1);
  tab3(tab);
  cerr << "/" << endl;
  direita->debug_com_tab(tab/1);
  tab3(tab);
  cerr << "/ ] FIM Divisao"<< endl;
}
