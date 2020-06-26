#include "Diario.h"
#include "Mensagem.h"
#include "Data.h"
#include <iostream>
#include <sstream>
#include "ObterDataTempo.h"
//#include <ctime>


Diario::Diario(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo), mensagens(nullptr), tamanhoDiario(0), capacidadeDiario(10)
{
    mensagens = new Mensagem[capacidadeDiario];
}

Diario::~Diario(){
    delete[] mensagens;
}

void Diario::adicionar(const std::string& mensagem)
{   
    
    // adicionar mensagem no array de mensagens
    if (tamanhoDiario >= capacidadeDiario){
        return;    
    }

    //Código para a mensagem escrita
    mensagens[tamanhoDiario].conteudo = mensagem;

    //Código para a data da mensagem
    std::string dataComparar;
    dataComparar = mensagens[tamanhoDiario].data.to_string();
    std::cout << "Data para comparar: " << dataComparar << std::endl;

    mensagens[tamanhoDiario].data.set_from_string(get_current_date()); //Setando valores de dia, mês e ano na mensagem
    std::cout << "Testando dia: " << mensagens[tamanhoDiario].data.dia << std::endl;
    std::cout << "Testando mes: " << mensagens[tamanhoDiario].data.mes << std::endl;
    std::cout << "Testando ano: " << mensagens[tamanhoDiario].data.ano << std::endl;

    //Código para a hora da mensagem
    std::string tempoComparar;
    tempoComparar = mensagens[tamanhoDiario].tempo.to_string();
    std::cout << "Tempo para comparar: " << tempoComparar << std::endl;
    mensagens[tamanhoDiario].tempo.set_from_string(get_current_time()); //Setando valores de horas, minutos e segundos na mensagem
    std::cout << "Testando horas: " << mensagens[tamanhoDiario].tempo.horas << std::endl;
    std::cout << "Testando minutos: " << mensagens[tamanhoDiario].tempo.minutos << std::endl;
    std::cout << "Testando segundos: " << mensagens[tamanhoDiario].tempo.segundos << std::endl;

    tamanhoDiario++;  
    
}

void Diario::escrever()
{
    // gravar as mensagens no disco
}



    /*
    std::string recebeData = get_current_date();
    std::string recebeTempo = get_current_time();
    char descarte;

    //Cadastrando data
    std::stringstream streamData(recebeData);

    streamData >> mensagens[tamanhoDiario].data.dia;
    streamData >> descarte; 
    streamData >> mensagens[tamanhoDiario].data.mes;
    streamData >> descarte;
    streamData >> mensagens[tamanhoDiario].data.ano;

    //Cadastrando hora da mensagem
    std::stringstream streamTempo(recebeTempo);

    streamTempo >> mensagens[tamanhoDiario].tempo.horas;
    streamTempo >> descarte; 
    streamTempo >> mensagens[tamanhoDiario].tempo.minutos;
    streamTempo >> descarte;
    streamTempo >> mensagens[tamanhoDiario].tempo.segundos;

    std::cout << mensagens[tamanhoDiario].data.dia << std::endl;
    std::cout << mensagens[tamanhoDiario].data.mes << std::endl;
    std::cout << mensagens[tamanhoDiario].data.ano << std::endl;
    std::cout << mensagens[tamanhoDiario].tempo.horas << std::endl;
    std::cout << mensagens[tamanhoDiario].tempo.minutos << std::endl;
    std::cout << mensagens[tamanhoDiario].tempo.segundos << std::endl;
    */