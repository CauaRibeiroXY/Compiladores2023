#ifndef _FLOAT_HPP_
#define _FLOAT_HPP_
#include "../Arvore.hpp"

using namespace std;

class FLOAT {
public:
  float valor;
  bool sinal; //true = +, false = -
  FLOAT();
  FLOAT(float valor);
  static FLOAT * extrai_FLOAT(No_arv_parse* no, bool sinal = true);

};

#endif