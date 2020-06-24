#include <iostream>
#include "App.h"

App::App(const std::string& nomeArquivo) : diario(nomeArquivo)
{

}

int App::executar(int argc, char* argv[]){

    //Entrada de forma incorreta (Passado apenas 1 parâmetro): Condição de erro
    if (argc == 1){
        return mostrarUso(argv[0]);
    }

    std::string segundoParametro = argv[1];

    if (segundoParametro == "add"){
        if (argc == 2){
            adicionar();
        } else{
            adicionar(argv[2]);
        }

    } else if (segundoParametro == "list"){
        listarMensagens();
        
    } else{
        return mostrarUso(argv[0]);
    }

    return 0; //Executou corretamente
        
} 

void App::adicionar(){
    //Pede mensagem para o usuário
    std::string mensagem;
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);

    adicionar(mensagem); //Chamando o outro método 'adicionar(string)'
}

void App::adicionar(const std::string mensagem){
    diario.adicionar(mensagem);
    diario.escrever();
}

int App::mostrarUso(const std::string nomePrograma){
    //Entrada de forma incorreta (Foi passado apenas 1 parâmetro): Condição de erro
    std::cout << "Uso: " << nomePrograma << " add <mensagem>" << std::endl;
    std::cout << "Uso: " << nomePrograma << " list" << std::endl;
    return 1;
}

void App::listarMensagens(){
    for (size_t i = 0; i<diario.tamanhoDiario;++i){
        const Mensagem& mensagem = diario.mensagens[i];
        std::cout << "- " << mensagem.conteudo << std::endl;

    }
}