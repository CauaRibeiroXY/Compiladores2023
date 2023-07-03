#include "FrameFuncao.hpp"
#include "../src-gram5/ExpressaoChamada.hpp"
#include <iostream>
using namespace std;

FrameFuncao::FrameFuncao() { }

FrameFuncao* FrameFuncao::gera_frame_de_funcao(Funcao* fun) {
  
  FrameFuncao* frame = new FrameFuncao();
  vector<string> var_frame;     // Lista das variáveis que são parâmetros de chamada
  frame->n_variaveis_no_frame = 0;

  // Calculando posição no frame dos parâmetros de entrada, e adicionando na tabela
  int p = fun->parametros.size();
  for( Variavel* v : fun->parametros ){
      FrameAcessoNoFrame *fa = new FrameAcessoNoFrame();
      fa->posicao_no_frame = p * 8;
      v->acesso_frame = fa;
      frame->symbol_table.insert( pair <string, FrameAcesso* > ( v->nome->nome, fa ) );
      var_frame.push_back(v->nome->nome);
      p--;
  }

  // Fazendo percurso na função para detectar as variáveis parâmetro de chamada
  var_in_frame(fun, var_frame);

  p = 0;
  for(string v : var_frame){
    if(frame->symbol_table.find(v) == frame->symbol_table.end()){
      frame->n_variaveis_no_frame++;
      FrameAcessoNoFrame *fa = new FrameAcessoNoFrame();
      fa->posicao_no_frame = -(40 + (p * 8));
      frame->symbol_table.insert( pair <string, FrameAcesso* > ( v, fa ) );
      p++;
    }
  }

  // Fazendo percurso e determinando a posição no frame e registradores
  FrameAcessoTemp::cout = 0;
  percurso_funcao(fun, frame->symbol_table);

  // Definindo o acesso frame da lista de variáveis
  for(Variavel* v : fun->variaveis){
    if(frame->symbol_table.find(v->nome->nome) != frame->symbol_table.end()){
      v->acesso_frame = frame->symbol_table.at(v->nome->nome);
    }
    else{ 
      // Caso a variável não foi declarada mas não usada, optei em deixá-la em pseudo-registradores, 
      // mas poderia ignorá-las para otimização
      FrameAcessoTemp *fa = new FrameAcessoTemp();
      fa->id = FrameAcessoTemp::cout;
      frame->symbol_table.insert( pair <string, FrameAcesso* > ( v->nome->nome, fa ) );
      v->acesso_frame = fa;
      FrameAcessoTemp::cout++;
    }
  }

  frame->n_param_entrada = fun->parametros.size();
  frame->n_maximo_param_saida = ExpressaoChamada::max_parametros;
  frame->n_pseudo_registradores = FrameAcessoTemp::cout;
  frame->tamanho_frame = 40 + ( 8 * frame->n_variaveis_no_frame ) + ( 8 * frame->n_maximo_param_saida );

  return frame;
}

void FrameFuncao::var_in_frame(Funcao* fun, vector<string> &var_frame){
  for(Comando* c : fun->comandos){
    c->var_in_frame(var_frame);
  }
}

void FrameFuncao::percurso_funcao(Funcao* fun, map < string, FrameAcesso* > &table){
  for(Comando* c : fun->comandos){
    c->percurso_funcao(table);
  }
}

void FrameFuncao::debug(){
  cout << "*********** Frame Funcao ***********" << endl;
  cout << "Tamanho do Frame: " << tamanho_frame << " bytes" << endl;
  cout << "Num parametros entrada: " << n_param_entrada << endl;
  cout << "Num parametros saida: " << n_maximo_param_saida << endl;
  cout << "Num pseudo registradores: " << n_pseudo_registradores << endl;
  cout << "Num variaveis no frame: " << n_variaveis_no_frame << endl;
  cout << "************************************" << endl;
  cout << "************SymbolTable************" << endl;
  for (auto const &pair: symbol_table) {
      cout << "[ " << pair.first << " : " << pair.second->debug() << " ]\n";
  }
  cout << "************************************" << endl;
}