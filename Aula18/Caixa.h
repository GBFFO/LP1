#ifndef CAIXA_H
#define CAIXA_H

#include <string>
#include "Funcionario.h"

class Caixa : public Funcionario{
    public:
        Caixa(std::string nomeCaixa);
        Caixa();
        ~Caixa();

};

#endif