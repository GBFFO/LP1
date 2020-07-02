#include "Diario.h"
#include "Mensagem.h"
#include "Data.h"
#include "ObterDataTempo.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>




Diario::Diario(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo)  //, mensagens(nullptr), tamanhoDiario(0), capacidadeDiario(10)  //CÓDIGO ANTIGO
{
    //std::vector<Mensagem> mensagens; //mensagens = new Mensagem[capacidadeDiario]; //CÓDIGO ANTIGO
    carregar();

}

Diario::~Diario(){
    //delete[] mensagens;   //CÓDIGO ANTIGO
}

void Diario::adicionar(const std::string& mensagem)
{   
    std::cout << "ADICIONANDO..." << std::endl;
    std::cout << "Quantidade de mensagens no início: " <<  mensagens.size() << std::endl; 
    std::cout << "Capacidade de mensagens no início: " <<  mensagens.capacity() << std::endl; 
    /* CÓDIGO ANTIGO
    // adicionar mensagem no array de mensagens
    if (tamanhoDiario >= capacidadeDiario){
        return;    
    }
    */

    //Código para a mensagem escrita
    Mensagem msg;
    msg.conteudo = mensagem; //mensagens[tamanhoDiario].conteudo = mensagem;
    msg.data.set_from_string(get_current_date()); //mensagens[tamanhoDiario].data.set_from_string(get_current_date()); //Setando valores de dia, mês e ano na mensagem
    msg.tempo.set_from_string(get_current_time()); //mensagens[tamanhoDiario].tempo.set_from_string(get_current_time()); //Setando valores de horas, minutos e segundos na mensagem
    mensagens.push_back(msg);

     //Código para comparar a data e hora da mensagem
    std::string dataComparar;
    std::string tempoComparar;
    dataComparar = msg.data.to_string();
    tempoComparar = msg.tempo.to_string();

//--------------------- CÓDIGO DA ATIVIDADE 01 MODIFICADO PARA FUNCIONAR NA ATIVIDADE 02------------------------

    std::ofstream arquivo_saida(nomeArquivo, std::ios::app); //Diário: Arquivo de saída
    std::ifstream arquivo_leitura; //Diário: Arquivo para leitura dos dados  

    arquivo_leitura.open(nomeArquivo); //Abrindo arquivo 'saida.txt'
        //Verificando se o arquivo está aberto
        if(!arquivo_leitura.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return;
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
        
//------------------ FIM DO CÓDIGO MODIFICADO DA ATIVIDADE 01 PARA A ATIVIDADE 02--------------------
    std::cout << "Quantidade de mensagens no final: " <<  mensagens.size() << std::endl; 
    std::cout << "Capacidade de mensagens no final: " <<  mensagens.capacity() << std::endl; 
    return;
}

void Diario::carregar(){
    std::cout << "CARREGANDO..." << std::endl;
    std::cout << "Quantidade de mensagens no início: " <<  mensagens.size() << std::endl; 
    std::cout << "Capacidade de mensagens no início: " <<  mensagens.capacity() << std::endl; 

    
    std::ofstream arquivo_saida(nomeArquivo, std::ios::app); //Diário: Arquivo de saída
    std::ifstream arquivo_leitura; //Diário: Arquivo para leitura dos dados  

    arquivo_leitura.open(nomeArquivo); //Abrindo arquivo 'saida.txt'
        //Verificando se o arquivo está aberto
        if(!arquivo_leitura.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return;
        }

    std::string stringVerificadora, conteudoMensagem;
    char descarte;
    int valor_dia, valor_mes, valor_ano;
    Mensagem msg;

    //Percorrendo o que já tem no diário e armazenando as informaçõs da mensagem: Data, Hora e Conteudo
    while (!arquivo_leitura.eof()){
        std::getline(arquivo_leitura, stringVerificadora);
        std::stringstream streamData(stringVerificadora);
        std::stringstream streamTempo(stringVerificadora);

        //Pulando linhas vazias 
        if(stringVerificadora.size() == 0){
            continue;
        }

        //Obtendo informações da DATA da mensagem
        if (stringVerificadora[0] == '#'){
            streamData >> descarte;
            streamData >> valor_dia; 
            streamData >> descarte;
            streamData >> valor_mes; 
            streamData >> descarte;
            streamData >> valor_ano; 

            continue;
        }

        //Obtendo informações do TEMPO e CONTEUDO da mensagem e armazenando informação da DATA
        if (stringVerificadora[0] == '-'){
            streamTempo >> descarte;
            streamTempo >> msg.tempo.horas; //mensagens[numMensagens].tempo.horas;
            streamTempo >> descarte;
            streamTempo >> msg.tempo.minutos; //mensagens[numMensagens].tempo.minutos;
            streamTempo >> descarte;
            streamTempo >> msg.tempo.segundos; ////mensagens[numMensagens].tempo.segundos;

            std::getline(streamTempo, conteudoMensagem);

            //Removendo primeiro espaço em branco no conteúdo da mensagem: https://pt.stackoverflow.com/questions/249077/remover-primeiro-e-%C3%BAltimo-caractere-de-uma-string
            conteudoMensagem = conteudoMensagem.substr(1, conteudoMensagem.length()-1);

            //mensagens[numMensagens].conteudo = conteudoMensagem;
            msg.conteudo = conteudoMensagem;

            //Armazenando informação da data da mensagem
            msg.data.dia = valor_dia; //mensagens[numMensagens].data.dia = valor_dia;
            msg.data.mes = valor_mes; //mensagens[numMensagens].data.mes = valor_mes; 
            msg.data.ano = valor_ano; //mensagens[numMensagens].data.ano = valor_ano;

            mensagens.push_back(msg);

        }
    }


    arquivo_leitura.close();
    std::cout << "Quantidade de mensagens no final: " <<  mensagens.size() << std::endl;
    std::cout << "Capacidade de mensagens no final: " <<  mensagens.capacity() << std::endl; 
    return;
}


std::vector<Mensagem*> Diario::procurar(const std::string palavra){
    std::cout << "PROCURANDO..." << std::endl; 
    std::cout << "Quantidade de mensagens: " <<  mensagens.size() << std::endl;
    std::cout << "Capacidade de mensagens: " <<  mensagens.capacity() << std::endl; 

    std::vector<Mensagem*> mensagensEncontradas;

    for (size_t i = 0; i < mensagens.size(); i++){
        if (std::string::npos != mensagens[i].conteudo.find(palavra)){
            //std::cerr << "A sentença <" << palavra << "> foi encontrada no diário." << std::endl;
            //std::cerr << "Endereço: " << &mensagens[i] << std::endl;
            mensagensEncontradas.push_back(&mensagens[i]);
        }
    }
    
    return mensagensEncontradas;

}

void Diario::escrever()
{
    // gravar as mensagens no disco
}

/* CÓDIGO ANTIGO
void Diario::aumentarCapacidade(){
    size_t capacidadeDuplicada;
    capacidadeDuplicada = 2*capacidadeDiario;

    Mensagem* vetorAuxiliar = new Mensagem[capacidadeDuplicada];

    //Passando conteúdo cadastrado no vetor 'mensagens' para um vetor auxiliar
    for(size_t i = 0; i<capacidadeDiario; i++){
        vetorAuxiliar[i] = mensagens[i];
        //std::cout << "Conteudo no vetor auxiliar " << i << ":" << vetorAuxiliar[i].conteudo << std::endl;
    }

    delete[] mensagens;
    
    mensagens = new Mensagem[capacidadeDuplicada]; //Criando o vetor mensagens com capacidade duplicada

    //Passando de volta o conteudo que foi armazenado no vetor auxiliar para o vetor mensagens "original"
        for(size_t i = 0; i<capacidadeDiario; i++){
        mensagens[i] = vetorAuxiliar[i];
        //std::cout << "Conteudo no vetor mensagens" << i << ":" << mensagens[i].conteudo << std::endl;
    }
    
    capacidadeDiario = capacidadeDuplicada;
    delete[] vetorAuxiliar;

}
*/

/*
void Diario::adicionarFormatada(const Mensagem& mensagem)
{
    Mensagem msg;
    char descarte;

    // Adiciona informações da mensagem
    std::string teste;
    //teste = "- 14:00:04 Gabriel Bessa de Freitas Fuezi Oliva";
    //teste = "# 25/06/2020";

    std::stringstream streamData(teste);
    std::stringstream streamTempo(teste);

    if(teste[0] == '-'){
        //std::cout << "É cerquilha '-'" << std::endl;

        streamTempo >> descarte;
        streamTempo >> msg.tempo.horas;
        streamTempo >> descarte;
        streamTempo >> msg.tempo.minutos;
        streamTempo >> descarte;
        streamTempo >> msg.tempo.segundos;

        std::getline(streamTempo, msg.conteudo);

    }

    if(teste[0] == '#'){

        streamData >> descarte;
        streamData >> msg.data.dia;
        streamData >> descarte;
        streamData >> msg.data.mes;
        streamData >> descarte;
        streamData >> msg.data.ano;

    }

}
*/

