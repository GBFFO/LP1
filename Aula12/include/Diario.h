#ifndef DIARIO_H
#define DIARIO_H

#include "Mensagem.h"

#include <string>
#include <vector>


struct Diario{
    Diario(const std::string& nomeArquivo); //Duvidas
    ~Diario(); //Destrutor

    std::string nomeArquivo;
    std::vector<Mensagem> mensagens;
    /* CÓDIGO ANTIGO
    Mensagem* mensagens; //Código antigo
    size_t tamanhoDiario; //Quantos elementos existem no diário //size_t guarda o maior tamanho que o computador suporta
    size_t capacidadeDiario;  //Capacidade máxima de mensagens suportada pelo diário
    */


    //Métodos
    void adicionar(const std::string& mensagem); //Adicionar a mensagem no diário
    std::vector<Mensagem*> procurar(const std::string palavra); //Procurar uma palavra no diário
    void carregar();

    //void aumentarCapacidade();
    void escrever(); //Guarda as mensagens no arquivo: grava as mensagens no arquivo
    void adicionarFormatada(const Mensagem& mensagem); //Adiciona mensagem já formatada

};

#endif