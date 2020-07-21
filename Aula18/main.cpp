#include <iostream>
#include "ClientePF.h"
#include "Conta.h"
#include "Agencia.h"
#include "ClientePJ.h"
#include "Fila.h"
#include "Gerente.h"
#include "Caixa.h"
#include "Seguranca.h"


int main(){
    //Declarações dos Clientes e Funcionários

    ClientePF cl1("Gabriel", "070.071.072-01");
    ClientePF cl2("Anna", "080.081.082-02");
    ClientePF cl3("Renato", "090.091.092-03");
    
    ClientePJ clpj1("gab01", "XX. XXX. XXX/XXXX-XX");
    ClientePJ clpj2("al02", "YY. YYY. YYY/YYYY-YY");
    ClientePJ clpj3("ren03", "ZZ. ZZZ. ZZZ/ZZZZ-ZZ");

    Gerente gerente1("Milla");
    Gerente gerente2("Bella");

    Caixa caixa1("Floquinho");
    Caixa caixa2("Brasileirinho");
    Caixa caixa3("Branquinho");
    Caixa caixa4("Amarelinha");

    Seguranca seguranca1;
    seguranca1.set_nome("Kim");
    Seguranca seguranca2;
    seguranca2.set_nome("Tobby");

    std::cout << std::endl << "# CLIENTES #" << std::endl;
    std::cout << "Nome do primeiro cliente PF: " << cl1.get_nomeCliente() << std::endl;
    std::cout << "Nome do segundo cliente PF: " << cl2.get_nomeCliente() << std::endl; 
    std::cout << "Nome do terceiro cliente PF: " << cl3.get_nomeCliente() << std::endl; 
    std::cout << "A razão social ('nome cliente') do primeiro cliente PJ: " << clpj1.get_nomeCliente() << std::endl;
    std::cout << "A razão social ('nome cliente') do segundo cliente PJ: " << clpj2.get_nomeCliente() << std::endl;
    std::cout << "A razão social ('nome cliente') do terceiro cliente PJ: " << clpj3.get_nomeCliente() << std::endl;

    std::cout << std::endl << "# FUNCIONÁRIOS #" << std::endl;
    std::cout << "O nome do primeiro gerente é: " << gerente1.get_nome() << std::endl;
    std::cout << "O nome do segundo gerente é: " << gerente2.get_nome() << std::endl;
    std::cout << "O nome do primeiro caixa é: " << caixa1.get_nome() << std::endl;
    std::cout << "O nome do segundo caixa é: " << caixa2.get_nome() << std::endl;
    std::cout << "O nome do terceiro caixa é: " << caixa3.get_nome() << std::endl;
    std::cout << "O nome do quarto caixa é: " << caixa4.get_nome() << std::endl;
    std::cout << "O nome do primeiro segurança é: " << seguranca1.get_nome() << std::endl;
    std::cout << "O nome do segundo segurança é: " << seguranca2.get_nome() << std::endl;

    return 0;
}