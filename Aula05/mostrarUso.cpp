
    #include "mostrarUso.h"
    #include <iostream>
    
    //Função que mostra como o programa funciona
    void mostrarUso(const std::string &nomePrograma){
        //Entrada de forma incorreta (Foi passado apenas 1 parâmetro): Condição de erro
        std::cout << "Uso: " << nomePrograma << " add <mensagem>" << std::endl;
        std::cout << "Uso: " << nomePrograma << " list" << std::endl;

    }