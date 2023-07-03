#include "ExpressaoVariavel.hpp"
#include <iostream>
#include "../debug-util.hpp"
#include <algorithm> //find
#include <stdexcept> // Incluir a biblioteca para usar std::runtime_error

using namespace std;
ExpressaoVariavel::ExpressaoVariavel() {
      acesso_frame = nullptr;
}

tuple<Tipo, int, float, bool> ExpressaoVariavel::avalia(stack<Tabela*>& stack_symbol_table) {
    auto tabela = stack_symbol_table.top(); // Obtém a tabela de símbolos do topo da pilha
    
    // Verifica se a variável está na tabela de símbolos
    if (tabela->tabela_simbolos.count(nome->nome) > 0) {
        auto simbolo = *(tabela->tabela_simbolos[nome->nome]);
        Tipo tipo = get<0>(simbolo);
        void* endereco = &simbolo;

        int valor_inteiro = 0;
        float valor_float = 0.0;
        bool valor_booleano = false;

        // Obtém o valor correspondente ao tipo
        switch (tipo) {
            case Tipo::INTEGER:
                valor_inteiro = get<1>(simbolo);
                break;
            case Tipo::FLOAT:
                valor_float = get<2>(simbolo);
                break;
            case Tipo::BOOL:
                valor_booleano = get<3>(simbolo);
                break;
        }

        return make_tuple(tipo, valor_inteiro, valor_float, valor_booleano);
    }

    // Lança uma exceção caso a variável não esteja na tabela de símbolos
    throw std::runtime_error("Variável não encontrada na tabela de símbolos");
}


void ExpressaoVariavel::var_in_frame( vector<string> &var_frame, bool chamada){
  if(chamada){
    if(find(var_frame.begin(), var_frame.end(), nome->nome) == var_frame.end()){
      var_frame.push_back(nome->nome);
    }
  }
}

void ExpressaoVariavel::percurso_funcao(  map < string, FrameAcesso* > &table ){
  if(table.find(nome->nome) != table.end()){
    acesso_frame = table.at(nome->nome); // Variável pertencente ao frame
  }
  else{ // Defino a variável como registrador temporário e adiciono na tabela
    FrameAcessoTemp *fa = new FrameAcessoTemp();
    fa->id = FrameAcessoTemp::cout;
    table.insert( pair <string, FrameAcesso* > ( nome->nome, fa ) );
    acesso_frame = fa;
    FrameAcessoTemp::cout++;
  }
}


void ExpressaoVariavel::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "VAR[" << nome->nome << "]" << endl;
}
