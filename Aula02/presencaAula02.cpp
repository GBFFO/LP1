#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::string mensagem;

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
        std::cout << "A mensagem escrita foi: " << mensagem << std::endl; //Mensagem escrita
        return 0;

    } else{
    //Mais de 2 argumentos
        //Imprimindo terceiro argumento
        std::cout << "A mensagem escrita foi: " << argv[2] << std::endl; //Mensagem escrita
    }

    return 0;
}