#include "Cliente.h"



Cliente::Cliente(std::string nomeCliente){
    this->nomeCliente = nomeCliente;
}

Cliente::Cliente(){

};


Cliente::~Cliente(){

};

std::string Cliente::get_nomeCliente(){
    return this->nomeCliente;
}

void Cliente::set_nomeCliente(std::string nomeCliente){
    this->nomeCliente = nomeCliente;
}