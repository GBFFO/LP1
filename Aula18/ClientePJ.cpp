#include "ClientePJ.h"
#include <string> 

int ClientePJ::quantidadeClientesPJ;

ClientePJ::ClientePJ(){
    quantidadeClientesPJ++;
};

ClientePJ::~ClientePJ(){

};

ClientePJ::ClientePJ(std::string razaoSocial, std::string cnpj){
    quantidadeClientesPJ++;
    set_nomeCliente(razaoSocial);
    this->cnpj = cnpj;
};

/*
std::string ClientePJ::get_razaoSocial(){
    return this->razaoSocial;
}

void ClientePJ::set_razaoSocial(std::string razaoSocial){
    this->razaoSocial = razaoSocial;
}
*/

std::string ClientePJ::get_cnpj(){
    return this->cnpj;
}

void ClientePJ::set_cnpj(std::string cnpj){
    this->cnpj = cnpj;
}

int ClientePJ::get_quantidadeClientesPJ(){
    return quantidadeClientesPJ;
}

