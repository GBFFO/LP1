#include "Cliente.h"

int Cliente::quantidadeClientes;

Cliente::Cliente(){
    quantidadeClientes += 1;
};

Cliente::~Cliente(){

};

Cliente::Cliente(std::string nomeCliente, std::string cpf){
    this->nomeCliente = nomeCliente;
    this->cpf = cpf;
    quantidadeClientes += 1;
};

std::string Cliente::get_nomeCliente(){
    return this->nomeCliente;
}

void Cliente::set_nomeCliente(std::string nomeCliente){
    this->nomeCliente = nomeCliente;
}

std::string Cliente::get_cpf(){
    return this->cpf;
}

void Cliente::set_cpf(std::string cpf){
    this->cpf = cpf;
}


int Cliente::get_quantidadeClientes(){
    return quantidadeClientes;
}
