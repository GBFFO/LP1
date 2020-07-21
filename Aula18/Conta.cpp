#include "Conta.h"

int Conta::quantidadeContas;

Conta::Conta(){
    quantidadeContas += 1;
};

Conta::~Conta(){

};

Conta::Conta(ClientePF &titular, Agencia &agencia, std::string numeroConta, double saldo){
    this->titular = titular;
    this->agencia = agencia;
    this->numero = numeroConta;
    this->saldo = saldo;
    quantidadeContas += 1;

};

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