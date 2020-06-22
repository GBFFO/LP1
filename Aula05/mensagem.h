#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

struct Tempo{
    int hora;
    int minuto;
    int segundo;
};

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Mensagem{
    Data data;
    Tempo horas;
    std::string conteudo;

    bool compararData(const Mensagem &outraMensagem){
        //data == outraMensagem.data; //Comparando se as datas das mensagens são as mesmas
    };
};

#endif