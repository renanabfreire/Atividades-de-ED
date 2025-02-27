#include "FilaSeq.h"

// Construtor: inicializa a fila com capacidade máxima de 100 elementos.
FilaSeq::FilaSeq() {
    inicio = 0;
    fim = -1;
    nElementos = 0;
    tamMax = 100;
    dados = new int[tamMax];
}

// Destrutor: libera a memória alocada para os dados.
FilaSeq::~FilaSeq() {
    delete[] dados;
}

bool FilaSeq::vazia() const {
    return (nElementos == 0);
}

bool FilaSeq::cheia() const {
    return (nElementos == tamMax);
}

int FilaSeq::tamanho() const {
    return nElementos;
}

int FilaSeq::primeiro() const {
    if (vazia())
        return -1; // Erro: fila vazia
    return dados[inicio];
}

bool FilaSeq::insere(int valor) {
    if (cheia())
        return false;
    fim = (fim + 1) % tamMax; // Implementação circular
    dados[fim] = valor;
    nElementos++;
    return true;
}

int FilaSeq::remove() {
    if (vazia())
        return -1;
    int res = primeiro();
    inicio = (inicio + 1) % tamMax; // Implementação circular
    nElementos--;
    return res;
}
