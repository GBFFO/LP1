#include <iostream>
#include "Cliente.h"
#include "Conta.h"
#include "Agencia.h"
#include "ClientePJ.h"
#include "Fila.h"




int main(){


    Cliente cl1("Gabriel", "070.071.072-01");
    Cliente cl2("Anna", "080.081.082-02");
    Cliente cl3("Renato", "090.091.092-03");
    
    ClientePJ clpj1("gab01", "XX. XXX. XXX/XXXX-XX");
    ClientePJ clpj2("al02", "YY. YYY. YYY/YYYY-YY");
    ClientePJ clpj3("ren03", "ZZ. ZZZ. ZZZ/ZZZZ-ZZ");

    std::cout << cl1.get_quantidadeClientes() << std::endl;

    std::cout << clpj2.get_quantidadeClientesPJ() << std::endl;

    // Utilizando filas distintas para clientes pessoas física e pessoas jurídica
    Fila<Cliente> filaPF(100);
    Fila<ClientePJ> filaPJ(100);

    filaPF.pop();
    filaPF.push(cl1);
    filaPF.push(cl2); 
    std::cout << "O último elemento é: " << filaPF.back().get_nomeCliente() << std::endl; 
    filaPF.push(cl3); 
    std::cout << "O último elemento é: " << filaPF.back().get_nomeCliente() << std::endl; 


    filaPJ.push(clpj1);
    filaPJ.push(clpj2);  
    std::cout << "O último elemento é: " << filaPJ.back().get_razaoSocial() << std::endl; 

    filaPJ.push(clpj3);
    std::cout << "A razão social do último elemento é: " << filaPJ.back().get_razaoSocial() << std::endl; 
    std::cout << "O CNPJ do último elemento da fila é: " << filaPJ.back().get_cnpj() << std::endl; 


    return 0;
}