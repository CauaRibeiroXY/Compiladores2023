#include "Variavel.hpp"
#include "ID.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;


vector<Variavel *> Variavel::extrai_lista_parametros(No_arv_parse *no)
{
  if (no->regra == 48)
  {
    vector<Variavel *> res;
    res = extrai_lista_parametros(no->filhos[0]);
    return res;
  }
  // 19) ARGS -> ARG , ARGS
  if (no->regra == 19)
  {
    vector<Variavel *> res;
    res.push_back(extrai_parametro(no->filhos[0]));
    vector<Variavel *> restante = extrai_lista_parametros(no->filhos[2]);
    res.insert(res.end(), restante.begin(), restante.end());
    return res;
  }
  // 20) ARGS -> ARG
  if (no->regra == 20)
  {
    vector<Variavel *> res;
    res.push_back(extrai_parametro(no->filhos[0]));
    return res;
  }
  // 21) ARGSX ->
  if (no->regra == 21)
    return vector<Variavel *>();
  // 22) ARG -> EXPRESSION_ART
  //Implementacao nao necessaria

  // 46) ARG -> IDENTIFIER : TYPE
  if (no->regra == 46)
  {
    vector<Variavel *> res;
    res.push_back(extrai_parametro(no));
    return res;
  }

  return vector<Variavel *>();
}
Variavel *Variavel::extrai_parametro(No_arv_parse *no)
{
  Variavel *res = new Variavel();
  // 46) ARG -> IDENTIFIER : TYPE
  res->nome = ID::extrai_ID(no->filhos[0]);
  res->tipo = ID::extrai_ID(no->filhos[2]->filhos[0]);
  
  return res;
}
vector<Variavel *> Variavel::extrai_lista_variaveis(No_arv_parse *no)
{
  if (no->regra == 6)
  {
    vector<Variavel *> res;
    res.push_back(extrai_parametro(no->filhos[0]->filhos[0]));
    return res;
  }
  return vector<Variavel *>();
}

Variavel *Variavel::extrai_variavel(No_arv_parse *no)
{

  Variavel *variavel = new Variavel();
  variavel->nome = ID::extrai_ID(no->filhos[1]);
  variavel->tipo = ID::extrai_ID(no->filhos[3]->filhos[0]);
  return variavel;
}

void Variavel::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "[" << nome->nome << ":" << tipo->nome << "] Variavel Declarada" << endl;
}
