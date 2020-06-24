#ifndef DIARIO_H
#define DIARIO_H

#include "Mensagem.h"

#include <string>

struct Diario{
    Diario(const std::string& nomeArquivo); //Duvidas
    std::string nomeArquivo;
    Mensagem* mensagens;
    size_t tamanhoDiario; //Quantos elementos existem no diário //size_t guarda o maior tamanho que o computador suporta
    size_t capacidadeDiario;  //Capacidade de mensagens do diário
    void adicionar(const std::string& mensagem); //Adicionar a mensagem no diário
    void escrever(); //Guarda as mensagens no arquivo: grava as mensagens no arquivo
    
};

#endif