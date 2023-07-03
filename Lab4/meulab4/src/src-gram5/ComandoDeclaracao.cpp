#include "ComandoDeclaracao.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoDeclaracao::ComandoDeclaracao()
{
  variavel = NULL;
  expressao = NULL;
}

tuple<Tipo, int, float, bool> ComandoDeclaracao::avalia_comando(stack<Tabela *> &pilha_de_tabelas)
{
  Tabela *tabela_atual = pilha_de_tabelas.top();
  string nome_variavel = variavel->nome->nome;

  // Verifica se a variável já está declarada na tabela atual
  if (tabela_atual->tabela_simbolos.find(nome_variavel) != tabela_atual->tabela_simbolos.end())
  {
    throw runtime_error("Erro: Variável já declarada.");
  }

  // Obtém o tipo da variável
  string tipo_variavel = variavel->tipo->nome;

  // Aloca memória e inicializa o valor da variável com base no tipo
  // Insere a variável na tabela de símbolos
  Valor *valor = nullptr;
  if (expressao != NULL)
  {
    // Avalia a expressão e obtém o resultado
    auto result = expressao->avalia(pilha_de_tabelas);
    Tipo tipo_expressao = get<0>(result);
    int valor_inteiro = get<1>(result);
    float valor_float = get<2>(result);
    bool valor_booleano = get<3>(result);

    // Aloca memória e inicializa o valor da variável com base no tipo
    if (tipo_variavel == "INTEGER")
    {
      int *valor_int = new int(valor_inteiro);
      valor = new Valor(Tipo::INTEGER, *valor_int, 0.0f, false);
      tabela_atual->adicionar_simbolo(nome_variavel, valor);
      return make_tuple(Tipo::INTEGER, valor_inteiro, 0, false);
    }
    else if (tipo_variavel == "FLOAT")
    {
      float *valor_f = new float(valor_float);
      valor = new Valor(Tipo::FLOAT, 0, *valor_f, false);
      tabela_atual->adicionar_simbolo(nome_variavel, valor);
      return make_tuple(Tipo::FLOAT, 0, valor_float, false);
    }
    else if (tipo_variavel == "BOOL")
    {
      bool *valor_bool = new bool(valor_booleano);
      valor = new Valor(Tipo::BOOL, 0, 0.0f, *valor_bool);
      tabela_atual->adicionar_simbolo(nome_variavel, valor);
      return make_tuple(Tipo::BOOL, 0, 0.0f, valor_booleano);
    }
    else
    {
      throw runtime_error("Erro: Tipo de variável inválido.");
    }
  }

  // Retorna a tupla com as informações da variável
  if (tipo_variavel == "INTEGER")
  {
    valor = new Valor(Tipo::INTEGER, 0, 0.0f, false);
    tabela_atual->adicionar_simbolo(nome_variavel, valor);
    return make_tuple(Tipo::INTEGER, 0, 0.0f, false);
  }
  else if (tipo_variavel == "FLOAT")
  {
    valor = new Valor(Tipo::FLOAT, 0, 0.0, false);
    tabela_atual->adicionar_simbolo(nome_variavel, valor);
    return std::make_tuple(Tipo::FLOAT, 0, 0.0f, false);
  }
  else if (tipo_variavel == "BOOL")
  {
    valor = new Valor(Tipo::BOOL, 0, 0.0f, false);
    tabela_atual->adicionar_simbolo(nome_variavel, valor);
    return std::make_tuple(Tipo::BOOL, 0, 0.0f, false);
  }
  else
  {
    throw std::runtime_error("Erro: Tipo de variável inválido.");
  }
}

void ComandoDeclaracao::var_in_frame(vector<string> &var_frame)
{
  if (expressao != NULL)
  {
    expressao->var_in_frame(var_frame, false);
  }
  else
  {

  }
}

void ComandoDeclaracao::percurso_funcao(map<string, FrameAcesso *> &table)
{
  if (table.find(variavel->nome->nome) != table.end())
  {
    variavel->acesso_frame = table.at(variavel->nome->nome); // Variável pertencente ao frame
  }
  else
  { // Defino a variável como registrador temporário e adiciono na tabela
    FrameAcessoTemp *fa = new FrameAcessoTemp();
    fa->id = FrameAcessoTemp::cout;
    table.insert(pair<string, FrameAcesso *>(variavel->nome->nome, fa));
    variavel->acesso_frame = fa;
    FrameAcessoTemp::cout++;
  }
  if (expressao != NULL)
  {
    expressao->percurso_funcao(table);
  }
}

void ComandoDeclaracao::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "INI DECLARACAO: " << variavel->nome << " = " << endl;
  expressao->debug_com_tab(tab + 1);
  tab3(tab);
  cerr << "FIM DECLARACAO" << endl;
  cerr << endl;
}