#include "ClientePF.h"

int ClientePF::quantidadeClientesPF;

ClientePF::ClientePF(){
    quantidadeClientesPF += 1;
};

ClientePF::~ClientePF(){

};

ClientePF::ClientePF(std::string nomeClientePF, std::string cpf){
    set_nomeCliente(nomeClientePF);
    this->cpf = cpf;
    quantidadeClientesPF += 1;
};

/*
std::string ClientePF::get_nomeClientePF(){
    return this->nomeClientePF;
}

void ClientePF::set_nomeClientePF(std::string nomeCliente){
    this->nomeClientePF = nomeClientePF;
}
*/

std::string ClientePF::get_cpf(){
    return this->cpf;
}

void ClientePF::set_cpf(std::string cpf){
    this->cpf = cpf;
}


int ClientePF::get_quantidadeClientesPF(){
    return quantidadeClientesPF;
}
