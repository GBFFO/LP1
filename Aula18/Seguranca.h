#ifndef SEGURANCA_H
#define SEGURANCA_H

#include <string>
#include "Funcionario.h"

class Seguranca : public Funcionario{
    public:
        Seguranca(std::string nomeCaixa);
        Seguranca();
        ~Seguranca();

};

#endif