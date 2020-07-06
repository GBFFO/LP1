#include <iostream>
#include "Conta.h"

int main(){
    Conta c, d;

    c.cliente = "Gabriel";
    c.numero = 001;
    c.saldo = 0;

    d.cliente = "Anna";
    d.numero = 002;
    d.saldo = 100;

    //Checando valores instanciados
    std::cout << "Nome do cliente C:" << c.cliente << std::endl;
    std::cout << "Numero da conta do cliente C:" << c.numero << std::endl;
    std::cout << "Saldo da conta do cliente C (antes):" << c.saldo << std::endl;
    std::cout << "Nome do cliente D:" << d.cliente << std::endl;
    std::cout << "Numero da conta do cliente D:" << d.numero << std::endl;
    std::cout << "Saldo da conta do cliente D:" << d.saldo << std::endl;
    std::cout << std::endl;

    //Operações
    c.deposita(350);
    c.saca(100);
    c.transfere(220, d);
    //Saldos após transações
    std::cout << "Saldo da conta do cliente C (após transações):" << c.saldo << std::endl;
    std::cout << "Saldo da conta do cliente D (após transações):" << d.saldo << std::endl;

    return 0;
}