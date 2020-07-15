#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

class ClientePJ{
    private:
        std::string razaoSocial;
        std::string cnpj;
        static int quantidadeClientesPJ;
    
    public:
    ClientePJ();
    ~ClientePJ();
    ClientePJ(std::string razaoSocial, std::string cnpj);

    //Métodos get
    std::string get_razaoSocial();
    std::string get_cnpj();
    int get_quantidadeClientesPJ();

    //Métodos set
    void set_razaoSocial(std::string razaoSocial);
    void set_cnpj(std::string razaoSocial);


};

#endif