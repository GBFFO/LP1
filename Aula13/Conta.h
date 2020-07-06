#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta{
    public:
        std::string cliente;
        int numero;
        double saldo;
        double limite;

        void saca(double valor);
        void deposita(double valor);
        void transfere(double valor, Conta &contaDestino);

};

#endif