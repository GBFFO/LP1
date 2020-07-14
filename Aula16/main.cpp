#include <iostream>
#include <string>
#include <vector>

#include "Funcionario.h"
#include "Empresa.h"


int main(){
    std::vector<Funcionario> funcionarios;
    int quantidadeFuncionarios;

    Empresa companhia;
    companhia.set_cnpj("XX.XXX.XXX/XXXX-XX");
    companhia.set_nomeEmpresa("America");
    
    std::cout << "Digite a quantidade de funcionários: ";
    std::cin >> quantidadeFuncionarios;

    for (int i=0; i < quantidadeFuncionarios; i++){
        Funcionario funcionario("Souza",15000,"01/01/2000","Futebol",companhia);
        funcionarios.push_back(funcionario);

    }

    std::vector<Funcionario>::iterator it;
    //Modificando salário
    for(it = funcionarios.begin(); it != funcionarios.end(); it++){
        if (it->get_departamento() == "Futebol"){
            it->set_salario(1.1*it->get_salario());
        }
    }

    //Imprimindo saída
    for(it = funcionarios.begin(); it != funcionarios.end(); it++){
        std::cout << "Nome = " << it->get_nome() << " | Salario = " << it->get_salario() << " | Data de admissão = " << it->get_dataAdmissao() << std::endl;
    }


//    for (auto x: funcionarios){
//        std::cout << "Nome = " << x.get_nome() << " | Salario = " << x.get_salario() << " | Data de admissão = " << x.get_dataAdmissao() << std::endl;
//    }

    return 0;

}