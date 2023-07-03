#include "Expressao.hpp"
#include "ExpressaoChamada.hpp"
#include <iostream>
#include <vector>

using namespace std;
ExpressaoChamada::ExpressaoChamada() {}

tuple<Tipo, int, float, bool> ExpressaoChamada::avalia(stack<Tabela *> &pilha_de_tabelas)
{
    return make_tuple(Tipo::BOOL, 0, 0.0f, false);
}

int ExpressaoChamada::max_parametros = 0;

vector<Expressao *> ExpressaoChamada::extrai_lista_expressoes_parametro(No_arv_parse *no)
{

    vector<Expressao *> res;


    if (no->regra == 19)
    {
        // 19) ARGS -> ARG , ARGS
        res = ExpressaoChamada::extrai_lista_expressoes_parametro(no->filhos[0]);
        vector<Expressao *> restante = extrai_lista_expressoes_parametro(no->filhos[2]);
        res.insert(res.end(), restante.begin(), restante.end());
        return res;
    }
    // 20) ARGS -> ARG
    if (no->regra == 20)
    {

        res = ExpressaoChamada::extrai_lista_expressoes_parametro(no->filhos[0]);
        return res;
    }

    if (no->regra == 21)
        return res; // 21) ARGSX ->
    
    if (no->regra == 22)
    {

        res.push_back(Expressao::extrai_expressao(no->filhos[0]));
        return res;
    }

    if (no->regra == 48)
    {
        res = ExpressaoChamada::extrai_lista_expressoes_parametro(no->filhos[0]);
        return res;
    }
    

    return vector<Expressao *>();
}



void ExpressaoChamada::var_in_frame(vector<string> &var_frame, bool chamada)
{
    for (Expressao *e : argumentos)
    {
        e->var_in_frame(var_frame, true);
    }
}

void ExpressaoChamada::percurso_funcao(map<string, FrameAcesso *> &table)
{
    if (ExpressaoChamada::max_parametros < argumentos.size())
    {
        ExpressaoChamada::max_parametros = argumentos.size();
    }
    for (Expressao *e : argumentos)
    {
        e->percurso_funcao(table);
    }
}
