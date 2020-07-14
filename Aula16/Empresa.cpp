#include "Empresa.h"

/*
Empresa::Empresa(std::string nomeEmpresa, std::string cnpj){
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
};

Empresa::~Empresa(){

};
*/
std::string Empresa::get_nomeEmpresa(){
    return this->nomeEmpresa;
}

void Empresa::set_nomeEmpresa(std::string nomeEmpresa){
    this->nomeEmpresa = nomeEmpresa;
}


std::string Empresa::get_cnpj(){
    return this->cnpj;
}

void Empresa::set_cnpj(std::string cnpj){
    this->cnpj = cnpj;
}