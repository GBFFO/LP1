#include <string>
#include "motor.hpp"

using namespace std;

class Carro{
    public:
    string tipo;
    string placa;
    int numPortas;
    int velocidade;
    string cor;
    Motor motor;
    static int numeroCarros;

    Carro(string tipo, string cor, int numPortas, string placa, int velocidade);
    Carro();
    ~Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};