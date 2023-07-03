#include "ComandoEscopo.hpp"

tuple<Tipo, int, float, bool> ComandoEscopo::avalia_comando(stack<Tabela *> &pilha_de_tabelas)
{
    // Faz uma cópia do topo da pilha de tabelas
    Tabela *topo_atual = pilha_de_tabelas.top();
    Tabela *novo_escopo = new Tabela(*topo_atual);

    // Adiciona o novo escopo à pilha de tabelas
    pilha_de_tabelas.push(novo_escopo);

    // Avalia os comandos dentro do escopo
    for (Comando *cmd : comandos)
    {
        cmd->avalia_comando(pilha_de_tabelas);
    }

    // Remove o escopo atual da pilha de tabelas
    pilha_de_tabelas.pop();

    // Retorna um valor padrão ou o resultado desejado
    return make_tuple(Tipo::INTEGER, 0, 0, false);
}

void ComandoEscopo::var_in_frame(vector<string>& var_frame) {
    for (auto& comando : comandos) {
        comando->var_in_frame(var_frame);
    }
}

void ComandoEscopo::percurso_funcao(map<string, FrameAcesso*>& table) {
    for (auto& comando : comandos) {
        comando->percurso_funcao(table);
    }
}
