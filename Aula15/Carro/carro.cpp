#include "carro.hpp"

int Carro::numeroCarros;

Carro::Carro(string tipo, string cor, int numPortas, string placa, int velocidade){
    this-> tipo = tipo;
    this->cor = cor;
    this->numPortas = numPortas;
    this-> placa = placa;
    this->velocidade = velocidade;
    numeroCarros += 1;
}

Carro::Carro(){
    this->tipo = "Hatch";
    this->cor = "Branco";
    this->numPortas = 2;
    this->placa = "XXX-0000";
    this->velocidade = 0;
    numeroCarros += 1;

}

Carro::~Carro(){


}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}