#include "Comando.hpp"
#include "ComandoAtribuicao.hpp"
#include "ComandoIf.hpp"
#include "ComandoDeclaracao.hpp"
#include "ID.hpp"
#include "Variavel.hpp"
#include "ComandoEscopo.hpp"
#include <iostream>
#include "../debug-util.hpp"

vector<Comando *> Comando::extrai_lista_comandos(No_arv_parse *no)
{

  // 10) Bloco_Codigo ->
  switch (no->regra)
  {
  case 10:
  {
    return vector<Comando *>();
  }
  // 9) Bloco_Codigo -> Codigo Bloco_Codigo
  case 9:
  {
    vector<Comando *> res;
    Comando *c = extrai_comando(no->filhos[0]->filhos[0]);
    if (c != NULL)
      res.push_back(c);
    vector<Comando *> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
    return res;
  }
  case 2:
  {
    // 2) CODIGO -> DECLARACAO ;
    vector<Comando *> res;
    res.push_back(extrai_comando(no->filhos[0]));
    return res;
  }
  case 3:
  {
    // 3) CODIGO -> ATRIBUICAO ;
    vector<Comando *> res;

    res.push_back(extrai_comando(no->filhos[0]));
    return res;
  }
  case 4:
  {
    // 4) CODIGO -> CONDICAO
    vector<Comando *> res;
    res.push_back(extrai_comando(no->filhos[0]));
    return res;
  }
  case 5:
  {
    // CODIGO -> CALL_FUNCTION
    vector<Comando *> res;
    res.push_back(extrai_comando(no->filhos[0]));
    return res;
  }
  case 6:
  {
    // CODIGO -> KW_RETURN EXPRESSION_LOGICA
    vector<Comando *> res;
    res.push_back(extrai_comando(no->filhos[0]));
    return res;
  }
case 7:
{
    // CODIGO -> { BLOCO_CODIGO }
    vector<Comando*> res;

    // Cria um novo objeto de ComandoEscopo
    ComandoEscopo* novo_escopo = new ComandoEscopo();

    // Extrai a lista de comandos do bloco de código
    novo_escopo->comandos = extrai_lista_comandos(no->filhos[1]);

    return res;
}
  case 8:
  {
    // CODIGO -> ;
    return vector<Comando *>();
  }
  
  case 15:
  {
    //CONDICAOELSE -> KW_ELSE CONDICAO
    // Como requisito do lab era apenas if e else, nao implementei elseif
    vector<Comando *> cmd;
    cmd.push_back(extrai_comando(no->filhos[1]));
    return cmd;
  }
  case 16:
  {
    //CONDICAOELSE -> KW_ELSE { BLOCO_CODIGO }
    vector<Comando *> cmd;
    cmd = extrai_lista_comandos(no->filhos[2]);
    return cmd;
  }
  case 17:
  {
    // CONDICAOELSE ->
    return vector<Comando *>();
  }
  default:
  {
    return vector<Comando *>();
  }
  }
}
Comando *Comando::extrai_comando(No_arv_parse *no)
{

  switch (no->regra)
  {
  case 11:
  {

    // 11) DECLARACAO -> KW_LET IDENTIFIER : TYPE
    ComandoDeclaracao *res = new ComandoDeclaracao();
    res->variavel = Variavel::extrai_variavel(no);
    return res;
  }
  case 12:
  {

    //  DECLARACAO -> KW_LET IDENTIFIER : TYPE = EXPRESSION_LOGICA
    ComandoDeclaracao *res = new ComandoDeclaracao();
    res->variavel = Variavel::extrai_variavel(no);
    res->expressao = Expressao::extrai_expressao(no->filhos[5]);
    return res;
  }
  case 13:
  { // 13) ATRIBUICAO -> IDENTIFIER = EXPRESSION_LOGICA

    ComandoAtribuicao *res13 = new ComandoAtribuicao();
    res13->esquerda = ID::extrai_ID(no->filhos[0]);
    res13->direita = Expressao::extrai_expressao(no->filhos[2]);

    return res13;
  }
 case 14:
{
    // CONDICAO -> KW_IF EXPRESSION_LOGICA { BLOCO_CODIGO } CONDICAOELSE
    
    ComandoIf *res = new ComandoIf();
    res->expressao = Expressao::extrai_expressao(no->filhos[1]);
    res->comando = extrai_lista_comandos(no->filhos[3]);
    res->comando_else = extrai_lista_comandos(no->filhos[5]);
    return res;
}
  default:
  {
    return NULL;
  }
  }
}

tuple<Tipo, int, float, bool> Comando::avalia_comando(stack<Tabela *> &simbolos)
{
  cout << "Executa comando genérico" << endl;
  return make_tuple(Tipo::INTEGER, 0, 0, false);
}

void Comando::var_in_frame( vector<string> &var_frame){

}

void Comando::percurso_funcao(  map < string, FrameAcesso* > &table ){

}

void Comando::debug_com_tab(int tab)
{
  tab3(tab);
  cerr << "Comando generico" << endl;
}
