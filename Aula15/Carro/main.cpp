#include <iostream>
#include "carro.hpp"

using namespace std;

int main(){
    Carro a;
    Carro c("Sedan","Vermelho",4,"XYZ-0101",0);

    //Carro: Personalizado
    cout << "Carro Personalizado de fárica:" << endl;
    cout << "Tipo do carro: " << c.tipo << endl;
    cout << "Quantidade de portas: " << c.numPortas << endl;
    cout << "Placa do carro: " << c.placa << endl;
    cout << "A cor do carro é: " << c.cor << endl;

    //Carro: Default
    cout << "Carro Básico de fábrica:" << endl;
    cout << "Tipo do carro: " << a.tipo << endl;
    cout << "Quantidade de portas: " << a.numPortas << endl;
    cout << "Placa do carro: " << a.placa << endl;
    cout << "A cor do carro é: " << a.cor << endl;
    cout << endl;
    cout << "Quantidade de carros fabricados: " << c.numeroCarros << endl;
    cout << endl;

    //Operações
    c.ligaCarro();
    cout << "A velocidade antes é: " << c.velocidade << "KM/H" << endl;
    c.acelera(50);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    c.freia (20);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    return 0;
}