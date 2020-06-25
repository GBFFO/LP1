#include "Diario.h"
#include "Mensagem.h"
#include <iostream>


Diario::Diario(const std::string& nomeArquivo) : nomeArquivo (nomeArquivo), capacidadeDiario(10), mensagens(nullptr), tamanhoDiario(0)
{
    mensagens = new Mensagem[capacidadeDiario];
}

void Diario::adicionar(const std::string& mensagem)
{
    // adicionar mensagem no array de mensagens
    //std::cout << "Entrou no 'adicionar(mensagem)'." << std::endl;
    //std::cout << "Mensagem: " << mensagem << std::endl;
    std::cout << "Tamanho do diario antes: " << tamanhoDiario << std::endl;

    if (tamanhoDiario < capacidadeDiario){
        mensagens[tamanhoDiario].conteudo = mensagem;
        tamanhoDiario++;       
    }
    
    std::cout << "Tamanho do diario após: " << tamanhoDiario << std::endl;
}

void Diario::escrever()
{
    // gravar as mensagens no disco
}