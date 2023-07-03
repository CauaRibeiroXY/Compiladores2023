#include "FrameAcessoTemp.hpp"

FrameAcessoTemp::FrameAcessoTemp(){}

string FrameAcessoTemp::debug(){
    return "Reg " + to_string( id );
}

int FrameAcessoTemp::cout = 0;

