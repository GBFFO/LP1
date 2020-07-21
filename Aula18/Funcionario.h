#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario{
    private: //Se utilizasse 'protected' as classes que herdam a classe 'Funcionario' acessariam o atributo 'nome' desta classe.
        std::string nome;

    public:
        Funcionario(std::string nome);
        Funcionario();
        ~Funcionario();

        std::string get_nome();
        void set_nome(std::string nome);
};

#endif