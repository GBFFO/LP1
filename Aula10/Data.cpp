#include "Data.h"
#include "ObterDataTempo.h"
#include "Mensagem.h"
#include <iostream>
#include <sstream>


Data::Data(): dia(0), mes(0), ano(0)
{

}


std::string Data::to_string(){
    std::stringstream stream;

    //Ajustando dia para formatação correta
    if (dia < 10) {
        stream << 0;
    }
    stream << dia;
    stream << '/';

    //Ajustando mes para formatação correta
    if (mes < 10) {
        stream << "0";
    }
    stream << mes << "/";
    stream << ano;

    return stream.str();

}

void Data::set_from_string(const std::string& data){
    //Cadastrando data: dia/mes/ano
    std::stringstream streamData(data);
    char descarte;

    streamData >> dia;
    streamData >> descarte; 
    streamData >> mes;
    streamData >> descarte;
    streamData >> ano;
}


