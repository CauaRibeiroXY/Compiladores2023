#ifndef _FRAME_ACESSO_TEMP_HPP_
#define _FRAME_ACESSO_TEMP_HPP_
#include "FrameAcesso.hpp"
#include <iostream>

using namespace std;

class FrameAcessoTemp : public FrameAcesso {
public:
  static int cout;
  int id; // id unico do pseudo-registrador/temporario.
  FrameAcessoTemp();
  string debug();
};

#endif
