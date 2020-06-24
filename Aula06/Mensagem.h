#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Data.h"
#include "Tempo.h"

#include <string>

struct Mensagem{
    Data data;
    Tempo tempo;
    std::string conteudo;

};

#endif