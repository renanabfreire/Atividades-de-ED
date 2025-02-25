#include <iostream>
#include "lista.h"

using namespace std;

int main() {
    Lista lista;

    // Teste de lista vazia e tamanho inicial
    cout << "Lista vazia? " << (lista.isVazia() ? "Sim" : "Não") << endl;
    cout << "Tamanho: " << lista.getTamanho() << "\n" << endl;

    // Inserção no início (insereInicio)
    cout << "Inserindo 10 na posição 1 (início)..." << endl;
    if(lista.insere(1, 10))
        cout << "Inserção bem-sucedida." << endl;
    else
        cout << "Falha na inserção." << endl;
    cout << "Elemento na posição 1: " << lista.elemento(1) << endl;
    cout << "Posição do valor 10: " << lista.posicao(10) << endl;
    cout << "Tamanho: " << lista.getTamanho() << "\n" << endl;

    // Inserção no meio (insereMeioLista)
    cout << "Inserindo 20 na posição 2..." << endl;
    if(lista.insere(2, 20))
        cout << "Inserção bem-sucedida." << endl;
    else
        cout << "Falha na inserção." << endl;
    cout << "Elemento na posição 2: " << lista.elemento(2) << endl;
    cout << "Posição do valor 20: " << lista.posicao(20) << endl;
    cout << "Tamanho: " << lista.getTamanho() << "\n" << endl;

    // Inserção no fim (insereFim)
    cout << "Inserindo 30 no fim da lista..." << endl;
    if(lista.insere(lista.getTamanho() + 1, 30))
        cout << "Inserção bem-sucedida." << endl;
    else
        cout << "Falha na inserção." << endl;
    cout << "Elemento na última posição: " << lista.elemento(lista.getTamanho()) << endl;
    cout << "Posição do valor 30: " << lista.posicao(30) << endl;
    cout << "Tamanho: " << lista.getTamanho() << "\n" << endl;

    // Acesso a um elemento fora dos limites
    cout << "Tentando acessar elemento na posição 5 (inexistente): " 
         << lista.elemento(5) << "\n" << endl;

    // Remoção do primeiro elemento (removeInicio)
    cout << "Removendo o elemento na posição 1..." << endl;
    int removido = lista.remove(1);
    if(removido != -1)
        cout << "Elemento removido: " << removido << endl;
    else
        cout << "Falha na remoção." << endl;
    cout << "Tamanho após remoção: " << lista.getTamanho() << endl;
    if(!lista.isVazia())
        cout << "Novo elemento na posição 1: " << lista.elemento(1) << "\n" << endl;

    // Remoção de elemento no meio/fim (removeMeioLista)
    cout << "Removendo o elemento na posição 2..." << endl;
    removido = lista.remove(2);
    if(removido != -1)
        cout << "Elemento removido: " << removido << endl;
    else
        cout << "Falha na remoção." << endl;
    cout << "Tamanho após remoção: " << lista.getTamanho() << "\n" << endl;

    // Tentativa de remoção de posição inválida
    cout << "Tentando remover elemento na posição 5 (inexistente): " 
         << lista.remove(5) << "\n" << endl;

    // Exibindo os elementos restantes
    cout << "Elementos restantes na lista:" << endl;
    for (int i = 1; i <= lista.getTamanho(); i++) {
        cout << "Posição " << i << ": " << lista.elemento(i) << endl;
    }

    return 0;
}
