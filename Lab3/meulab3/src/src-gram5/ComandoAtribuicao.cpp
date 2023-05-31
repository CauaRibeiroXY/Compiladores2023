#include "ComandoAtribuicao.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoAtribuicao::ComandoAtribuicao() {}

tuple<Tipo, int, float, bool> ComandoAtribuicao::avalia_comando(stack<Tabela*>& pilha_de_tabelas) {
    tuple<Tipo, int, float, bool> resultado;

    if (esquerda == nullptr || direita == nullptr) {
        throw runtime_error("Erro: ComandoAtribuicao com ponteiro nulo.");
    }
    auto x = esquerda->nome;
    auto s = pilha_de_tabelas.top();
    // Verifica se a variável já existe na tabela de símbolos
    if (pilha_de_tabelas.top()->tabela_simbolos.find(esquerda->nome) != pilha_de_tabelas.top()->tabela_simbolos.end()) {
        // Avalia a expressão da direita
        resultado = direita->avalia(pilha_de_tabelas);

        // Verifica se o tipo de dado da expressão da direita é compatível com a variável da esquerda
        if (get<0>(resultado) == Tipo::INTEGER) {
            int valor = get<1>(resultado);
            Valor* valorPtr = new Valor(Tipo::INTEGER, valor, 0.0f, false);
            pilha_de_tabelas.top()->adicionar_simbolo(esquerda->nome, valorPtr);
        }
        else if (get<0>(resultado) == Tipo::FLOAT) {
            float valor = get<2>(resultado);
            Valor* valorPtr = new Valor(Tipo::FLOAT, 0, valor, false);
            pilha_de_tabelas.top()->adicionar_simbolo(esquerda->nome, valorPtr);
        }
        else if (get<0>(resultado) == Tipo::BOOL) {
            bool valor = get<3>(resultado);
            Valor* valorPtr = new Valor(Tipo::BOOL, 0, 0.0f, valor);
            pilha_de_tabelas.top()->adicionar_simbolo(esquerda->nome, valorPtr);
        }
        else {
            throw runtime_error("Erro: Tipo de dado inválido para atribuição.");
        }
    } else {
        throw runtime_error("Erro: Variável não declarada.");
    }

    return resultado;
}



void ComandoAtribuicao::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "INI ATRIB: " << esquerda->nome << " = " << endl;
  direita->debug_com_tab(tab + 1);
  tab3(tab);
  cerr << "FIM ATRIB" << endl;
  cerr << endl;
}
