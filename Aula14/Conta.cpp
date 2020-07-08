#include "Conta.h"

void Conta::saca(double valor){
    this->saldo -= valor;
}

void Conta::deposita(double valor){
    this->saldo += valor;
}

void Conta::transfere(double valor, Conta &contaDestino){
    this->saldo -= valor;
    contaDestino.deposita(valor);
}