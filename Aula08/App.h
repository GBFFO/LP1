#ifndef APP_H
#define APP_H

#include "Diario.h"
struct App{
    Diario diario;

    App(const std::string& nomeArquivo);
    int executar(int argc, char* argv[]); //Função executar: recebe 'argc' e 'argv' e retorna se o programa funcionou ou não
    int mostrarUso(const std::string nomePrograma);
    void adicionar();
    void adicionar(const std::string mensagem);
    void listarMensagens();
    void escrever();

    /*Anotações aula (23/06):
        - Construtor é uma função que é chamada quando se cria um objeto (função que é chamada para inicializar uma variável de determinado tipo)
        - Funções dentro de strucs são chamadas de métodos (métodos também são chamados de funções membro)
        - Variáveis que pertencem a um struc: Atributos
        - 'const': não cria uma cópia do valor, usa-se o próprio valor (quando não se vai alterar o parâmetro passado)
        - &: quando se coloca '&' não se pode passar um valor nulo (não é opcional); 
        - *: quando se coloca uma referência '*', pode-se passar um valor ou passar nulo.
        - Quando se colocar 'App::funcaoX' está sendo informado que a 'funcaoX' pertence ao struct 'App'
        - Ensinado como inicializar as variáveis de uma struct
    */
};

#endif