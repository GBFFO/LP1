#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Empresa.h"

class Funcionario{
    private:
        std::string nome;
        double salario;
        std::string dataAdmissao;
        std::string departamento;
        Empresa empresa;

    public:
        Funcionario(std::string nome, double salario, std::string dataAdmissao, std::string departamento, Empresa empresa);
        ~Funcionario();
        std::string get_nome();
        void set_nome(std::string nome);

        double get_salario();
        void set_salario(double salario); 

        std::string get_dataAdmissao();
        void set_dataAdmissao(std::string dataAdmissao);

        std::string get_departamento();
        void set_departamento(std::string departamento);

        Empresa get_empresa();
        //void set_empresa(Empresa empresa);


};

#endif