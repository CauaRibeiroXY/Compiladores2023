#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_
#include "../Arvore.hpp"
using namespace std;

class INTEGER {
public:
  int valor;
  bool sinal; //true = +, false = -
  INTEGER(int valor);
  INTEGER();
  static INTEGER * extrai_INTEGER(No_arv_parse* no,bool sinal = true);

};

#endif
