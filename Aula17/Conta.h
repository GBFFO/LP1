#ifndef CONTA_H
#define CONTA_H

#include <string>
#include "Cliente.h"
#include "Agencia.h"

class Conta{
    public:
        Cliente titular;
        Agencia agencia;
        std::string numero;
        double saldo;
        static int quantidadeContas;
        Conta();
        ~Conta();
        Conta(Cliente &titular, Agencia &agencia, std::string numeroConta, double saldo);
        

        void saca(double valor);
        void deposita(double valor);
        void transfere(double valor, Conta &contaDestino);

};

#endif