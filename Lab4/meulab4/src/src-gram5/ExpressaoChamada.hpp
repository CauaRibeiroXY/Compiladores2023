#ifndef EXPRESSAO_CHAMADA_HPP
#define EXPRESSAO_CHAMADA_HPP
#include "Expressao.hpp"
#include "Variavel.hpp"
#include "ID.hpp"
#include "../Arvore.hpp"
#include "../Frame/FrameAcesso.hpp"
#include <vector>
#include <tuple>
using namespace std;

class ExpressaoChamada : public Expressao
{
public:
    ID *nome_funcao;
    vector<Expressao *> argumentos;
    static int max_parametros;

    ExpressaoChamada();


    void percurso_funcao(map<string, FrameAcesso *> &table);

    void var_in_frame(vector<string> &var_frame, bool chamada);

    static vector<Expressao*> extrai_lista_expressoes_parametro(No_arv_parse* no);

    virtual tuple<Tipo, int, float, bool> avalia(stack<Tabela *> &pilha_de_tabelas);
};

#endif // EXPRESSAO_CHAMADA_HPP
