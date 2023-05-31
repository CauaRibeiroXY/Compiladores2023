#include "Analisador.hpp"
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

Analisador::Analisador()
{
  Tabela *tabela_simbolos = new Tabela();
  pilha_de_tabelas.push(tabela_simbolos);
}

string Analisador::calcula_ultimo_valor(Funcao* f,const vector<tuple<Tipo, int, float, bool>>& params) {
  tuple<Tipo, int, float, bool> resultado;
  pilha_de_tabelas.top()->adicionar_parametros(f->parametros, params);
  
  
  for (Comando* c : f->comandos) {
    resultado = c->avalia_comando(pilha_de_tabelas);
  }
  


// Extrai o valor correspondente do tipo da tupla e converte para string
if (get<0>(resultado) == Tipo::INTEGER) {
  return to_string(get<1>(resultado));
} else if (get<0>(resultado) == Tipo::FLOAT) {
  float valor = get<2>(resultado);

  // Converte o valor para string com duas casas decimais
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << valor;

  return oss.str();
} else if (get<0>(resultado) == Tipo::BOOL) {
  return (get<3>(resultado)) ? "true" : "false";
} else {
  throw std::runtime_error("Erro: Tipo de valor inválido.");
}

}


