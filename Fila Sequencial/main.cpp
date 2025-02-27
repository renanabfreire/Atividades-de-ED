#include <iostream>
#include "FilaSeq.h"

using namespace std;

int main() {
    FilaSeq fila;

    // Testa se a fila está vazia
    if (fila.vazia()) {
        cout << "A fila está vazia." << endl;
    } else {
        cout << "A fila não está vazia." << endl;
    }

    // Insere alguns elementos
    cout << "\nInserindo elementos:" << endl;
    for (int i = 1; i <= 5; i++) {
        int valor = i * 10;
        if (fila.insere(valor)) {
            cout << "Inserido: " << valor << endl;
        } else {
            cout << "Falha ao inserir: " << valor << " (fila cheia)" << endl;
        }
    }

    // Testa se a fila não está vazia
    if (!fila.vazia()) {
        cout << "\nA fila não está vazia após inserções." << endl;
    }

    // Consulta o primeiro elemento
    cout << "Primeiro elemento: " << fila.primeiro() << endl;

    // Exibe o tamanho da fila
    cout << "Tamanho da fila: " << fila.tamanho() << endl;

    // Remove todos os elementos e os exibe
    cout << "\nRemovendo elementos:" << endl;
    while (!fila.vazia()) {
        int removido = fila.remove();
        cout << "Removido: " << removido << endl;
    }

    // Verifica se a fila ficou vazia
    if (fila.vazia()) {
        cout << "\nA fila está vazia após remoções." << endl;
    }

    // Insere elementos até encher a fila para testar o método 'cheia'
    cout << "\nInserindo elementos para encher a fila:" << endl;
    for (int i = 0; i < 100; i++) {
        if (!fila.insere(i)) {
            cout << "Falha ao inserir " << i << ": a fila está cheia." << endl;
            break;
        }
    }

    if (fila.cheia()) {
        cout << "A fila está cheia." << endl;
    } else {
        cout << "A fila não atingiu a capacidade máxima." << endl;
    }

    return 0;
}
