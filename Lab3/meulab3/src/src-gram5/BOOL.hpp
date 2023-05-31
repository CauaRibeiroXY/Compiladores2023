#ifndef _BOOL_HPP_
#define _BOOL_HPP_
#include "../Arvore.hpp"

using namespace std;

class BOOL {
public:
  bool valor;
  BOOL();
  static BOOL * extrai_BOOL(No_arv_parse* no);
};

#endif