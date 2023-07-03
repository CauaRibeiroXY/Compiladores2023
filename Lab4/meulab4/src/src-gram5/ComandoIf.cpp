#include "ComandoIf.hpp"

ComandoIf::ComandoIf() {
    expressao = nullptr;
    comando = vector<Comando*>();
    comando_else = vector<Comando*>();
}

tuple<Tipo, int, float, bool> ComandoIf::avalia_comando(stack<Tabela*>& pilha_de_tabelas) {
    if (expressao != nullptr) {
        // Avaliar a expressão lógica
        auto resultado = expressao->avalia(pilha_de_tabelas);

        // Verificar se a expressão é verdadeira
        bool condicao = get<3>(resultado);
        if (condicao) {
            // Executar os comandos do bloco "if"
            vector<tuple<Tipo, int, float, bool>> resultados;
            for (auto cmd : comando) {
                auto res = cmd->avalia_comando(pilha_de_tabelas);
                
                // Se necessário, trate o resultado da execução do comando "if" aqui

                resultados.push_back(res);
            }

            // Retornar o resultado da execução dos comandos "if"
            return resultados.back();
        } else {
            // Executar os comandos do bloco "else" (se houver)
            vector<tuple<Tipo, int, float, bool>> resultados;
            for (auto cmd : comando_else) {
                auto res = cmd->avalia_comando(pilha_de_tabelas);
                
                // Se necessário, trate o resultado da execução do comando "else" aqui

                resultados.push_back(res);
            }

            // Retornar o resultado da execução dos comandos "else"
            return resultados.back();
        }
    }

    // Retornar um valor padrão se a expressão for nula ou não houver comando a ser executado
    return make_tuple(Tipo::BOOL, 0, 0.0f, false);
}

void ComandoIf::var_in_frame(vector<string>& var_frame) {
    expressao->var_in_frame(var_frame, false);
    for (auto& cmd : comando) {
        cmd->var_in_frame(var_frame);
    }
    for (auto& cmd : comando_else) {
        cmd->var_in_frame(var_frame);
    }
}

void ComandoIf::percurso_funcao(map<string, FrameAcesso*>& table) {
    expressao->percurso_funcao(table);
    for (auto& cmd : comando) {
        cmd->percurso_funcao(table);
    }
    for (auto& cmd : comando_else) {
        cmd->percurso_funcao(table);
    }
}
