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
