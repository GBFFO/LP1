#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>


class  Empresa{
    private:
        std::string nomeEmpresa;
        std::string cnpj;

    public:
        //Empresa(std::string nomeEmpresa, std::string cnpj);
        //~Empresa();
        std::string get_nomeEmpresa();
        void set_nomeEmpresa(std::string nomeEmpresa);
        std::string get_cnpj();
        void set_cnpj(std::string cnpj);

};





#endif