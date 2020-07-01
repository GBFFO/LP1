#ifndef DATA_H
#define DATA_H

#include <string>

struct Data{
    Data(); //Construtor
    unsigned dia;
    unsigned mes;
    unsigned ano;

    //'data' é a string no formato DD/MM/AAAA
    void set_from_string(const std::string& data);
    std::string to_string();

};

#endif