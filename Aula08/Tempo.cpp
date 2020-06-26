#include "Tempo.h"
#include "ObterDataTempo.h"
#include "Mensagem.h"
#include <iostream>
#include <sstream>

Tempo::Tempo(): horas(0), minutos(0), segundos(0)
{

}

std::string Tempo::to_string(){
    return get_current_time();
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