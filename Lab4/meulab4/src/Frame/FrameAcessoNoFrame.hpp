#ifndef _FRAME_ACESSO_NO_FRAME_HPP_
#define _FRAME_ACESSO_NO_FRAME_HPP_
#include "FrameAcesso.hpp"
#include <iostream>

using namespace std;

class FrameAcessoNoFrame : public FrameAcesso {
public:
  int posicao_no_frame;
  // Acesso sera FP+posicao_no_frame. Exemplos
  // posicao_no_frame=40, 48, 56, etc.
  FrameAcessoNoFrame();
  string debug();
};

#endif
