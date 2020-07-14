#include "Funcionario.h"
#include "Empresa.h"



Funcionario::Funcionario(std::string nome, double salario, std::string dataAdmissao, std::string departamento, Empresa empresa)
{
    this->nome = nome;
    this->salario = salario;
    this->dataAdmissao = dataAdmissao;
    this->departamento = departamento;
    this->empresa = empresa;
};

Funcionario::~Funcionario(){

};


std::string Funcionario::get_nome(){
    return this->nome;
}

void Funcionario::set_nome(std::string nome){
    this->nome = nome;
}

double Funcionario::get_salario(){
    return this->salario;
}

void Funcionario::set_salario(double salario){
    this->salario = salario;
}

std::string Funcionario::get_dataAdmissao(){
    return this->dataAdmissao;
}

void Funcionario::set_dataAdmissao(std::string dataAdmissao){
    this->dataAdmissao = dataAdmissao;
}

std::string Funcionario::get_departamento(){
    return this->departamento;
}

void Funcionario::set_departamento(std::string departamento){
    this->departamento = departamento;
}


Empresa Funcionario::get_empresa(){
    return this->empresa;
}

/*
void Funcionario::set_empresa(Empresa empresa){
    this->empresa = empresa;
}
*/