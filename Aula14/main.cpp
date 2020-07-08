#include <iostream>
#include "Cliente.h"
#include "Conta.h"
#include "Agencia.h"



int main(){
    Conta g, a;
    Cliente c1, c2;
    Agencia ag1, ag2;

    ag1.nomeAgencia = "Rio Branco";
    ag1.codigoAgencia = "001";
    ag2.nomeAgencia = "Prudente";
    ag2.codigoAgencia = "002";


    c1.nome = "Gabriel";
    c1.cpf = "070.071.072-01";
    g.titular = c1;
    g.numero = "001";
    g.saldo = 0;
    g.agencia = ag1;


    c2.nome = "Anna";
    c2.cpf = "080.081.082-01";
    a.titular = c2;
    a.numero = "002";
    a.saldo = 100;
    a.agencia = ag2;


    //Checando valores instanciados
    std::cout << "################### GABRIEL ###################" << std::endl;

    std::cout << "Nome do cliente G:" << g.titular.nome << std::endl;
    std::cout << "CPF do cliente G:" << g.titular.cpf << std::endl;
    std::cout << "Numero da conta do cliente G:" << g.numero << std::endl;
    std::cout << "Saldo da conta do cliente G (antes):" << g.saldo << std::endl;
    std::cout << "Nome da agência do cliente G:" << g.agencia.nomeAgencia << std::endl;
    std::cout << "Codigo da agência do cliente G:" << g.agencia.codigoAgencia << std::endl;



    std::cout << "################### ANNA LARISSA ###################" << std::endl;

    std::cout << "Nome do cliente A:" << a.titular.nome << std::endl;
    std::cout << "CPF do cliente A:" << a.titular.cpf << std::endl;
    std::cout << "Numero da conta do cliente A:" << a.numero << std::endl;
    std::cout << "Saldo da conta do cliente A:" << a.saldo << std::endl;
    std::cout << "Nome da agência do cliente G:" << a.agencia.nomeAgencia << std::endl;
    std::cout << "Codigo da agência do cliente G:" << a.agencia.codigoAgencia << std::endl;


    //Operações
    g.deposita(350);
    g.saca(100);
    g.transfere(220, a);

    //Saldos após transações
    std::cout << "################### APÓS OPERAÇÕES BANCÁRIAS ###################" << std::endl;

    std::cout << "Saldo da conta do cliente G (após transações):" << g.saldo << std::endl;
    std::cout << "Saldo da conta do cliente A (após transações):" << a.saldo << std::endl;
    std::cout << std::endl;
    return 0;
}