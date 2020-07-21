#ifndef GERENTE_H
#define GERENTE_H

#include <string>
#include "Funcionario.h"

class Gerente : public Funcionario{
    public:
        Gerente(std::string nomeGerente);
        Gerente();
        ~Gerente();

};

#endif