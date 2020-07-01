#include "Diario.h"
#include "Mensagem.h"
#include "Data.h"
#include "ObterDataTempo.h"

#include <iostream>
#include <sstream>
#include <fstream>


Diario::Diario(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo), mensagens(nullptr), tamanhoDiario(0), capacidadeDiario(10)
{
    mensagens = new Mensagem[capacidadeDiario];
    carregar();

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

    mensagens[tamanhoDiario].data.set_from_string(get_current_date()); //Setando valores de dia, mês e ano na mensagem
    dataComparar = mensagens[tamanhoDiario].data.to_string();

    //Código para a hora da mensagem
    std::string tempoComparar;

    mensagens[tamanhoDiario].tempo.set_from_string(get_current_time()); //Setando valores de horas, minutos e segundos na mensagem
    tempoComparar = mensagens[tamanhoDiario].tempo.to_string();

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
    tamanhoDiario++;  
    return;
}

Mensagem* Diario::procurar(const std::string palavra){
    //std::cerr << "Sentença digitada para a busca:" << palavra << std::endl;

    //int encontrouPalavra = 0;
    for (size_t i = 0; i < tamanhoDiario; i++){
        if (std::string::npos != mensagens[i].conteudo.find(palavra)){
            std::cerr << "A sentença <" << palavra << "> foi encontrada no diário." << std::endl;
            std::cerr << "Endereço: " << &mensagens[i] << std::endl;
            return &mensagens[i];
            //encontrouPalavra = 1;
        }
    }
            std::cerr << "A sentença <" << palavra << "> NÃO foi encontrada no diário." << std::endl;

    return nullptr;

}


void Diario::carregar(){
    
    std::ofstream arquivo_saida(nomeArquivo, std::ios::app); //Diário: Arquivo de saída
    std::ifstream arquivo_leitura; //Diário: Arquivo para leitura dos dados  

    arquivo_leitura.open(nomeArquivo); //Abrindo arquivo 'saida.txt'
        //Verificando se o arquivo está aberto
        if(!arquivo_leitura.is_open()){
            std::cerr << "O arquivo não pôde ser lido." << std::endl;
            return;
        }

    int numMensagens = 0;
    std::string stringVerificadora, conteudoMensagem;
    char descarte;
    int valor_dia, valor_mes, valor_ano;

    //Percorrendo o que já tem no diário e armazenando as informaçõs da mensagem: Data, Hora e Conteudo
    while (!arquivo_leitura.eof()){
        std::getline(arquivo_leitura, stringVerificadora);
        std::stringstream streamData(stringVerificadora);
        std::stringstream streamTempo(stringVerificadora);

        //Pulando linhas vazias 
        if(stringVerificadora.size() == 0){
            continue;
        }

        //Verificando se precisa aumentar a capacidade do diário
        if (numMensagens >= capacidadeDiario){
            aumentarCapacidade();
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
            streamTempo >> mensagens[numMensagens].tempo.horas;
            streamTempo >> descarte;
            streamTempo >> mensagens[numMensagens].tempo.minutos;
            streamTempo >> descarte;
            streamTempo >> mensagens[numMensagens].tempo.segundos;

            std::getline(streamTempo, conteudoMensagem);

            //Removendo primeiro espaço em branco no conteúdo da mensagem: https://pt.stackoverflow.com/questions/249077/remover-primeiro-e-%C3%BAltimo-caractere-de-uma-string
            conteudoMensagem = conteudoMensagem.substr(1, conteudoMensagem.length()-1);

            mensagens[numMensagens].conteudo = conteudoMensagem;

            //Armazenando informação da data da mensagem
            mensagens[numMensagens].data.dia = valor_dia;
            mensagens[numMensagens].data.mes = valor_mes;
            mensagens[numMensagens].data.ano = valor_ano;

            /*
            //Verificando se tudo foi armazenado corretamente
            std::cout << "MENSAGEM NÚMERO:" << numMensagens << std::endl;
            std::cout << "Dia da mensagem:" << mensagens[numMensagens].data.dia << std::endl;
            std::cout << "Mes da mensagem:" << mensagens[numMensagens].data.mes << std::endl;
            std::cout << "Ano da mensagem:" << mensagens[numMensagens].data.ano << std::endl;
            std::cout << "Hora da mensagem:" << mensagens[numMensagens].tempo.horas << std::endl;
            std::cout << "Minutos da mensagem:" << mensagens[numMensagens].tempo.minutos << std::endl;
            std::cout << "Segundos da mensagem:" << mensagens[numMensagens].tempo.segundos << std::endl;
            std::cout << "Conteudo da mensagem:" << mensagens[numMensagens].conteudo << std::endl;
            std::cout << std::endl;
            */
        }
        tamanhoDiario = numMensagens;
        numMensagens++;
    }

    arquivo_leitura.close();

}

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

void Diario::escrever()
{
    // gravar as mensagens no disco
}
