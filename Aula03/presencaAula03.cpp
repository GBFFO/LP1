#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    std::string mensagem;
    std::ofstream arquivo_saida("saida.txt", std::ios::app); //Arquivo de saída

    //Entrada de forma incorreta (Apenas 1 argumento)
    if (argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

    //Verificando se o segundo argumento é 'add'
    if (std::string(argv[1]) != "add"){
        std::cout << "O segundo argumento precisa ser 'add'" << std::endl;
            return -1;
    }

    //2 argumentos
    if (argc == 2){
        //Pede mensagem para o usuário
        std::cout << "Digite a mensagem: ";
        std::getline(std::cin, mensagem);

    } else{
    //Mais de 2 argumentos
        mensagem = argv[2]; //Armazenando mensagem
    }

    std::cout << "A mensagem escrita foi: " << mensagem << std::endl; //Mensagem escrita
    arquivo_saida << mensagem << std::endl; //Escrevendo mensagem no arquivo de saída

    return 0;
}