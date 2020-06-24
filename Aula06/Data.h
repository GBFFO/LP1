#ifndef DATA_H
#define DATA_H

#include <string>

struct Data{
    unsigned ano;
    unsigned mes;
    unsigned dia;

    //Funções dentro de strucs são chamadas de métodos (métodos também são chamados de funções membro)
    //Variáveis que pertencem a um struc: Atributos

    //'data' é a string no formato DD/MM/AAAA
    void set_from_string(const std::string& data);

};

#endif