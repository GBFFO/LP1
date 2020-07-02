#ifndef TEMPO_H
#define TEMPO_H

#include <string>

struct Tempo{
    Tempo(); //Construtor
    unsigned horas;
    unsigned minutos;
    unsigned segundos;

    //'tempo' é a string no formato HH:MM:SS
    void set_from_string(const std::string& tempo);
    std::string to_string();

};

#endif