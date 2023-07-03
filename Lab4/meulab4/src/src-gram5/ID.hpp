#ifndef _ID_HPP_
#define _ID_HPP_
#include <string>
#include "../Arvore.hpp"
#include "../Frame/FrameAcesso.hpp"
using namespace std;

class ID
{
public:
  string nome;
  FrameAcesso *acesso_frame;

  static ID *extrai_ID(No_arv_parse *no);
};

#endif
