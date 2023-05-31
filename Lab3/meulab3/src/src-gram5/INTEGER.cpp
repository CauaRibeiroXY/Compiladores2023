#include "INTEGER.hpp"
#include <stdlib.h>

INTEGER::INTEGER(){}

INTEGER::INTEGER(int valor) {
    this->valor = valor;
    this->sinal = (valor >= 0); // definindo o sinal baseado no valor
}


INTEGER* INTEGER::extrai_INTEGER(No_arv_parse* no,bool sinal){
  INTEGER* res = new INTEGER();
    if (sinal) {
        //  36) FACTOR -> INTEGER_LITERAL 
        res->valor = atoi(no->dado_extra.c_str());
    } else {
        //  33) FACTOR -> - INTEGER_LITERAL
        res->valor = -atoi(no->dado_extra.c_str());
    }
    return res;
}

