    #include "Data.h"
    #include "Diario.h"

    #include <iostream>
    #include <sstream>
    #include <string>

    int main(int argc, char* argv[])
    {
        std::string data = "25/06/2020 gabriel bessa";
        Data d;

        std::stringstream stream(data);
        //std::string resultado = stream.str() //Transformando o stream em uma string chanamada 'resultado'
        char descarte;

        stream >> d.dia;
        stream >> descarte; 
        stream >> d.mes;
        stream >> descarte;
        stream >> d.ano;

        std::cout << d.dia << std::endl;
        std::cout << d.mes << std::endl;
        std::cout << d.ano << std::endl;

        return 0;
    }