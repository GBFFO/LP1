#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente{
    private:
        std::string nomeCliente;

    public:
        Cliente(std::string nomeCliente);
        Cliente();
        ~Cliente();

        std::string get_nomeCliente();
        void set_nomeCliente(std::string nomeCliente);

};
#endif