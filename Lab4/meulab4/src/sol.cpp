#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stack>
using namespace std;

#include "Gramatica.hpp"
#include "TabelaLR1.hpp"
#include "Arvore.hpp"
#include "Parser.hpp"
#include "src-gram5/Funcao.hpp"
#include "src-gram5/Analisador.hpp"
#include "Frame/FrameFuncao.hpp"

int main(int argc, char *argv[])
{
  if (argc != 3 && argc != 1)
  {
    cerr << "Parametros nomes dos arquivos: 1) csv com gramática e 2) csv com tabela LR1" << endl;
    return 1;
  }
  string nome_gramatica, nome_tab_lr1;
  if (argc == 1)
  {
    // cerr << "Valores padrao utilizados: gramatica.conf e tabela_lr1.conf" << endl;
    nome_gramatica = string("gramatica.conf");
    nome_tab_lr1 = string("tabela_lr1.conf");
  }
  else
  {
    nome_gramatica = string(argv[1]);
    nome_tab_lr1 = string(argv[2]);
  }

  ifstream arq_gramatica(nome_gramatica);
  ifstream arq_tabela_lr1(nome_tab_lr1);
  if (arq_tabela_lr1.fail() || arq_gramatica.fail())
  {
    cerr << "Falha ao abrir arquivos: " << ((arq_gramatica.fail()) ? nome_gramatica : "") << ", " << ((arq_tabela_lr1.fail()) ? nome_tab_lr1 : "") << endl;
    return 1;
  }
  Parser parser(arq_gramatica, arq_tabela_lr1);
  parser.tabela.debug();
  parser.gram.debug();

  Arvore_parse arv = parser.executa_parse(cin);
  cerr << "Parse executado" << endl;
  arv.debug();
  Funcao *func = Funcao::extrai_funcao(arv.raiz);

  if (func == NULL)
  {
    cerr << "FUNC NULL" << endl;
  }
  else
  {

    vector<tuple<Tipo, int, float, bool>> parametros;

    // Criando as três tuplas e adicionando ao vector
    tuple<Tipo, int, float, bool> tupla1(Tipo::INTEGER, 10, 0.0, false);
    tuple<Tipo, int, float, bool> tupla2(Tipo::INTEGER, 7, 0.0, false);
    tuple<Tipo, int, float, bool> tupla3(Tipo::INTEGER, 12, 0.0, false);

    parametros.push_back(tupla1);
    parametros.push_back(tupla2);
    parametros.push_back(tupla3);

    Analisador ana;
    cout << "Ultimo valor calculado:" << endl;
    cout << ana.calcula_ultimo_valor(func, parametros) << endl;
    FrameFuncao *frame = FrameFuncao::gera_frame_de_funcao(func);
  }

  return 0;
}
