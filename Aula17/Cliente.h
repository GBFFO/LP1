#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>


class Cliente{
    private:
        std::string nomeCliente;
        std::string cpf;
        static int quantidadeClientes;

    public:
        Cliente();
        ~Cliente();
        Cliente(std::string nomeCliente, std::string cpf);

        //Métodos get
        std::string get_nomeCliente();
        std::string get_cpf();
        int get_quantidadeClientes();

        //Métodos set
        void set_nomeCliente(std::string nomeCliente);
        void set_cpf(std::string cpf);


};

#endif