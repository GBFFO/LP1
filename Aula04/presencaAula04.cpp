#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    std::string mensagem;
    std::string segundoParametro;
    std::ofstream arquivo_saida("saida.txt", std::ios::app); //Arquivo de saída

    //Entrada de forma incorreta (Passado apenas 1 parâmetro): Condição de erro
    if (argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

    segundoParametro = argv[1]; //String recebe o segundo parâmetro passado

    //Verificando se o segundo parâmetro é diferente de 'add' ou 'list': Condição de erro
    if ((segundoParametro != "add") && (segundoParametro != "list")){
        std::cout << "O segundo parâmetro passado precisa ser 'add' ou 'list'" << std::endl;
            return -1;
    }

    //COMANDO: 'list' ou 'add' ?
    //Comando 1: 'add'
    if (segundoParametro == "add"){
        //2 parâmetros
        if (argc == 2){
            //Pede mensagem para o usuário
            std::cout << "Digite a mensagem: ";
            std::getline(std::cin, mensagem);

        } else{
        //Mais de 2 parâmetros
            mensagem = argv[2]; //Armazenando mensagem
        }

        std::cout << "A mensagem escrita foi: " << mensagem << std::endl; //Mensagem escrita

        //Verificando se o arquivo foi criado de forma correta: Condição de erro
        //if(!arquivo_saida.is_open()){
            //std::cerr << "O arquivo não pôde ser criado." << std::endl;
            //return -1;
        //}

        arquivo_saida << mensagem << std::endl; //Escrevendo mensagem no arquivo de saída
        std::cout << "Mensagem adicionada!" << std::endl; //Mensagem escrita
    }

    //Comando 2: 'list'
    if (segundoParametro == "list"){
        std::ifstream arquivo_leitura; //Arquivo para ler o dados
    
        arquivo_leitura.open("saida.txt"); //Abrindo arquivo 'saida.txt'

        //Verificando se o arquivo está aberto
        if(!arquivo_saida.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return -1;
        }

        std::string stringLida;
        int numeroLinha = 0;
        std::cout << "----- LISTA -----" << std::endl;
            //Percorrendo o arquivo 'saida.txt' e escrevendo as strings encontradas em uma lista
            while (!arquivo_saida.eof()){
                numeroLinha++;
                std::getline(arquivo_leitura, stringLida);

                //Critério de parada
                if(stringLida.size() == 0){
                    continue;
                }

                std::cout << numeroLinha << ". " << stringLida << std::endl; //Escrevendo string lida
            }
        arquivo_leitura.close();
        return 0;
        
    }

    return 0;
}