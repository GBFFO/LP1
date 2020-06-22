#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "mostrarUso.h"
#include "mensagem.h"
#include "data.h"
#include "diario.h"

std::string format_current_date(const std::string& format){
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date(){
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
    return format_current_date("%H:%M:%S");
}


int main(int argc, char *argv[]){
    std::string mensagem;
    std::string segundoParametro;
    std::ofstream arquivo_saida("saida.txt", std::ios::app); //Diário: Arquivo de saída
    std::ifstream arquivo_leitura; //Diário: Arquivo para leitura dos dados
    

    //Entrada de forma incorreta (Passado apenas 1 parâmetro): Condição de erro
    if (argc == 1){
        mostrarUso(argv[0]);
        return -1;
    }

    arquivo_leitura.open("saida.txt"); //Abrindo arquivo 'saida.txt'
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

        //Verificando se o arquivo está aberto
        if(!arquivo_leitura.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return -1;
        }

        std::string stringVerificadora;
        std::string dataHoje;
        int encontrouData = 0;

        dataHoje = "# " + get_current_date();//Data de hoje formatada utilizada para verificação
        //Percorrendo o diário e verificando se a data na qual o usuário está adicionando a mensagem já existe no diário
        while (!arquivo_leitura.eof()){
            std::getline(arquivo_leitura, stringVerificadora);

            //Pulando linhas vazias 
            if(stringVerificadora.size() == 0){
                continue;
            }

            //Teste para verificar se encontrou a data de hoje no diaário
            if (stringVerificadora == dataHoje){
                encontrouData = 1;
            }

        }

        //Se nenhuma mensagem tiver sido adicionada hoje, adiciona-se no diário a data de hoje com a formatação '# DD/MM/AAAA'
        if (encontrouData == 0){
            arquivo_saida << dataHoje << std::endl; //Escrevendo data de hoje no diário
        }

        arquivo_saida << "- " << get_current_time() << " " << mensagem << std::endl; //Escrevendo mensagem no diário
        std::cout << "A mensagem escrita foi: " << mensagem << std::endl; //Mensagem escrita
        std::cout << "Mensagem adicionada!" << std::endl; //Mensagem escrita
        arquivo_leitura.close();
        return 0;
    }

    //Comando 2: 'list'
    if (segundoParametro == "list"){

        //Verificando se o arquivo está aberto
        if(!arquivo_leitura.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return -1;
        }

        std::string stringLida;
        int numeroLinha = 0;
        //std::cout << "---------- LISTA DE MENSAGENS ESCRITAS ----------" << std::endl;
            //Percorrendo o arquivo 'saida.txt' e escrevendo as strings encontradas (em cada linha) em uma lista
            while (!arquivo_leitura.eof()){
                //numeroLinha++;
                std::getline(arquivo_leitura, stringLida);

                //Pulando linhas vazias 
                if(stringLida.size() == 0){
                    continue;
                }

                //Não escreve na lista caso seja uma data
                if (stringLida[0] != '#'){
                    std::cout << stringLida << std::endl; //Escrevendo string lida
                }
            }

        arquivo_leitura.close();
        return 0;
        
    }

    return 0;
}