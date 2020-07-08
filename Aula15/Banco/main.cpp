#include <iostream>
#include "Cliente.h"
#include "Conta.h"
#include "Agencia.h"



int main(){
    Agencia ag1("Rio Branco", "001");
    Agencia ag2("Prudente", "002");

    Cliente cl1("Gabriel", "070.071.072-01");
    Cliente cl2("Anna", "080.081.082-02");
    Cliente cl3("Renato", "090.091.092-03");
    Cliente cl4;

    Conta g(cl1,ag1,"001.001.001", 0);
    Conta a(cl2,ag2,"002.002.002", 100);

    
    //Checando valores instanciados
    std::cout << "################### GABRIEL ###################" << std::endl;

    std::cout << "Nome do cliente G:" << g.titular.nomeCliente << std::endl;
    std::cout << "CPF do cliente G:" << g.titular.cpf << std::endl;
    std::cout << "Numero da conta do cliente G:" << g.numero << std::endl;
    std::cout << "Saldo da conta do cliente G (antes):" << g.saldo << std::endl;
    std::cout << "Nome da agência do cliente G:" << g.agencia.nomeAgencia << std::endl;
    std::cout << "Codigo da agência do cliente G:" << g.agencia.codigoAgencia << std::endl;

    std::cout << "################### ANNA LARISSA ###################" << std::endl;

    std::cout << "Nome do cliente A:" << a.titular.nomeCliente << std::endl;
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
    std::cout << "################### SALDOS APÓS OPERAÇÕES BANCÁRIAS ###################" << std::endl;

    std::cout << "Saldo da conta do cliente G (após transações):" << g.saldo << std::endl;
    std::cout << "Saldo da conta do cliente A (após transações):" << a.saldo << std::endl;
    std::cout << std::endl;
    std::cout << "Quantidade total de contas criadas: " << g.quantidadeContas << std::endl;
    std::cout << "Quantidade total de clientes do banco: " << cl1.quantidadeClientes << std::endl;

    return 0;
}