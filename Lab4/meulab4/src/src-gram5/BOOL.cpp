#include "BOOL.hpp"
#include <cstring>


BOOL::BOOL() { }

BOOL *BOOL::extrai_BOOL(No_arv_parse* no){
    // 31) FACTOR -> KW_TRUE
    BOOL* res = new BOOL();
    if(strcmp(no->dado_extra.c_str(), "true")==0){
    	res->valor = true;
    } else {
    	res->valor = false;
    }
    return res; 
}