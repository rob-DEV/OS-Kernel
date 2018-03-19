//
// Created by dev on 19/03/18.
//

#include "video.h"

Video::Video(){
    pos = 0;
    off = 0;
    videomem = (unsigned short*)0xb8000;
}

Video::~Video(){}

void Video::clear(){
    unsigned int i;
    for(i=0;i<(80*25);i++){
        videomem[i] = (unsigned short)' '|0x0700;
    }
    pos = 0;
    off = 0;
}

void Video::write(char *cp){
    char *str = cp, *ch;
    for(ch=str;*ch;ch++){
        put(*ch);
    }
}

void Video::put(char c){
    if(pos>=80){
        pos = 0;
        off+=80;
    }
    if(off>=(80*25)){
        clear();
    }

    videomem[off+pos] = (unsigned short)c|0x0700;
    pos++;
}