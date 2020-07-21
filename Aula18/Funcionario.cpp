#include "Funcionario.h"

Funcionario::Funcionario(std::string nome){
    this->nome = nome;
};

Funcionario::Funcionario(){

};

Funcionario::~Funcionario(){

};

std::string Funcionario::get_nome(){
    return this->nome;
}

void Funcionario::set_nome(std::string nome){
    this->nome = nome;
}