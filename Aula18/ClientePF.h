#ifndef CLIENTEPF_H
#define CLIENTEPF_H

#include <string>
#include "Cliente.h"


class ClientePF : public Cliente{
    private:
//std::string nomeClientePF;
        std::string cpf;
        static int quantidadeClientesPF;

    public:
        ClientePF();
        ~ClientePF();
        ClientePF(std::string nomeClientePF, std::string cpf);

        //Métodos get
//std::string get_nomeClientePF();
        std::string get_cpf();
        int get_quantidadeClientesPF();

        //Métodos set
//void set_nomeClientePF(std::string nomeClientePF);
        void set_cpf(std::string cpf);


};

#endif