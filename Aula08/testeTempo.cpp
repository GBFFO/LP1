    #include "Tempo.h"
    #include "Diario.h"

    #include <iostream>
    #include <sstream>
    #include <string>

    int main(int argc, char* argv[])
    {
        std::string tempo = "12:15:56 Gabriel Bessa";
        Tempo t;

        std::stringstream stream(tempo);
        char descarte;

        stream >> t.horas;
        stream >> descarte; 
        stream >> t.minutos;
        stream >> descarte;
        stream >> t.segundos;

        std::cout << t.horas << std::endl;
        std::cout << t.minutos << std::endl;
        std::cout << t.segundos << std::endl;

        return 0;
    }