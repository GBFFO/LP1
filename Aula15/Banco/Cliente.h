#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>


class Cliente{
    public:
        std::string nomeCliente;
        std::string cpf;
        static int quantidadeClientes;
        Cliente();
        ~Cliente();
        Cliente(std::string nomeCliente, std::string cpf);

};

#endif