#include "FLOAT.hpp"
#include <stdlib.h>

FLOAT::FLOAT() {}

FLOAT::FLOAT(float valor) {
    this->valor = valor;
    this->sinal = (valor >= 0); // definindo o sinal baseado no valor
}


FLOAT *FLOAT::extrai_FLOAT(No_arv_parse *no, bool sinal)
{
  FLOAT *res = new FLOAT();

  if (sinal)
  {
      // 37) FACTOR -> FLOAT_LITERAL
    res->valor = atof(no->dado_extra.c_str());

  }else{
      // 34) FACTOR -> - FLOAT_LITERAL
    res->valor = -atof(no->dado_extra.c_str());
  }


  return res;
}