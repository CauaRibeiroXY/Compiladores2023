#include "Tabela.hpp"
#include <iostream>
using namespace std;

Tabela::Tabela() {}

void Tabela::adicionar_simbolo(string nome, Valor* valor) {
    // Verifica se o símbolo já existe na tabela de símbolos
    if (tabela_simbolos.count(nome) > 0) {
        tabela_simbolos[nome] = valor; // Atualiza o valor do símbolo existente
    } else {
        tabela_simbolos.insert({nome, valor}); // Adiciona um novo símbolo
    }
}


void Tabela::adicionar_parametros(const vector<Variavel*>& parametros, const vector<tuple<Tipo, int, float, bool>>& valores) {
    if (parametros.empty()) {
        return;  // Retorna imediatamente se não houver parâmetros
    }

    for (size_t i = 0; i < parametros.size(); i++) {
        Variavel* variavel = parametros[i];
        tuple<Tipo, int, float, bool> valor = valores[i];

        Tipo tipo = get<0>(valor);
        int valorInteiro = get<1>(valor);
        float valorFloat = get<2>(valor);
        bool valorBooleano = get<3>(valor);

        Valor* novoValor = new Valor(tipo, valorInteiro, valorFloat, valorBooleano);
        adicionar_simbolo(variavel->nome->nome, novoValor);
    }
}



Valor* Tabela::obter_valor(string nome) {
    auto it = tabela_simbolos.find(nome);
    if (it != tabela_simbolos.end()) {
        return it->second;
    }
    return nullptr;  // Retorna nullptr se o símbolo não for encontrado na tabela
}

void Tabela::imprimir_tabela_simbolos() {
    for (const auto& entry : tabela_simbolos) {
        const string& nome = entry.first;
        Valor* valor = entry.second;

        cout << "Nome: " << nome << ", Tipo: ";

        if (valor != nullptr) {
            Tipo tipo = get<0>(*valor);

            switch (tipo) {
                case Tipo::INTEGER:
                    cout << "INTEGER, Valor: " << get<1>(*valor);
                    break;
                case Tipo::FLOAT:
                    cout << "FLOAT, Valor: " << get<2>(*valor);
                    break;
                case Tipo::BOOL:
                    cout << "BOOL, Valor: " << (get<3>(*valor) ? "true" : "false");
                    break;
                default:
                    cout << "Tipo de valor inválido";
            }
        } else {
            cout << "Valor nulo";
        }

        cout << endl;
    }
}


