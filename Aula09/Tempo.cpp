#include "Tempo.h"
#include "ObterDataTempo.h"
#include "Mensagem.h"
#include <iostream>
#include <sstream>

Tempo::Tempo(): horas(0), minutos(0), segundos(0)
{

}

std::string Tempo::to_string(){

    std::stringstream stream;
    //Ajustando horas para formatação correta
    if (horas < 10) {
        stream << 0;
    }
    stream << horas;
    stream << ':';

    //Ajustando minutos para formatação correta
    if (minutos < 10) {
        stream << "0";
    }
    stream << minutos << ":";

    //Ajustando segundos para formatação correta
    if (segundos < 10) {
        stream << "0";
    }

    stream << segundos;

    return stream.str();

}

void Tempo::set_from_string(const std::string& tempo){
    std::stringstream streamTempo(tempo);
    char descarte;

    streamTempo >> horas;
    streamTempo >> descarte;
    streamTempo >> minutos;
    streamTempo >> descarte;
    streamTempo >> segundos;
    
}