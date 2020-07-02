#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Data.h"
#include "Tempo.h"

#include <string>

struct Mensagem{
    std::string conteudo;
    Data data;
    Tempo tempo;
    
};

#endif