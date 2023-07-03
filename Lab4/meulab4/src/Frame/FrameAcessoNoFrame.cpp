#include "FrameAcessoNoFrame.hpp"

FrameAcessoNoFrame::FrameAcessoNoFrame(){}

string FrameAcessoNoFrame::debug(){
    return to_string( posicao_no_frame ) + "(%rbp)";
}
