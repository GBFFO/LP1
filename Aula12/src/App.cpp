#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "App.h"
#include "Mensagem.h"

App::App(const std::string& nomeArquivo) : diario(nomeArquivo)
{

}

int App::executar(int argc, char* argv[]){

    //Entrada de forma incorreta (Passado apenas 1 parâmetro): Condição de erro
    if (argc == 1){
        return mostrarUso(argv[0]);
    }

    std::string comando = argv[1];

    if (comando == "add"){
        if (argc == 2){
            adicionar();
        } else{
            adicionar(argv[2]);
        }

    } else if (comando == "list"){
        listarMensagens();

    } else if (comando == "procurar"){
        if (argc > 2){
            procurar(argv[2]);
        } else{
            mostrarUso(argv[0]);
        }
                
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
    std::cout << "Uso: " << nomePrograma << " procurar <palavra>" << std::endl;

    return 1;
}

void App::procurar(const std::string palavra){
    
    std::vector<Mensagem*> mensagensEncontradas = diario.procurar(palavra);
    std::cout << "Quantidade de mensagens que contêm a sentença digitada no diário: " << mensagensEncontradas.size() << std::endl;
    for(size_t i=0; i < mensagensEncontradas.size(); i++){
        std::cout << mensagensEncontradas[i]->conteudo << std::endl;
        
    }

    return;
}

void App::listarMensagens(){
    
    std::ifstream arquivo_leitura; //Diário: Arquivo para leitura dos dados
    arquivo_leitura.open("saida.txt"); //Abrindo arquivo 'saida.txt'
    //Verificando se o arquivo está aberto
    if(!arquivo_leitura.is_open()){
        std::cerr << "O arquivo não pôde ser lido." << std::endl;
        return;////return -1;
    }

    std::string stringLida;
    int numeroLinha = 0;
    //Percorrendo o arquivo 'saida.txt' e escrevendo as strings encontradas (em cada linha) em uma lista
    while (!arquivo_leitura.eof()){
        std::getline(arquivo_leitura, stringLida);
        //Pulando linhas vazias 
        if(stringLida.size() == 0){
            continue;
        }
        //Não escreve na lista caso seja uma data
        if (stringLida[0] != '#'){
            numeroLinha++; //Quantide de mensagens
            std::cout << stringLida << std::endl; //Escrevendo string lida
        }
    }
    arquivo_leitura.close();

    //diario.tamanhoDiario = numeroLinha; //Teste
    //std::cout << "diario.tamanhoDiario: " << diario.tamanhoDiario << std::endl; //Teste

    /*CODIGO DO PROFESSOR

    for (size_t i = 0; i<diario.tamanhoDiario;++i){
        const Mensagem& mensagem = diario.mensagens[i];
        std::cout << "- " << mensagem.conteudo << std::endl;

    }
    */
}