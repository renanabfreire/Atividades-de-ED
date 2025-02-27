#ifndef FILASEQ_H
#define FILASEQ_H

class FilaSeq {
private:
    int inicio;
    int fim;
    int nElementos;
    int tamMax;
    int* dados;

public:
    // Construtor
    FilaSeq();

    // Destrutor
    ~FilaSeq();

    // Verifica se a fila está vazia
    bool vazia() const;

    // Verifica se a fila está cheia
    bool cheia() const;

    // Obtém o tamanho da fila
    int tamanho() const;

    // Consulta o elemento do início da fila
    // Retorna -1 se a fila estiver vazia
    int primeiro() const;

    // Insere um elemento no fim da fila.
    // Retorna false se a fila estiver cheia, true caso contrário.
    bool insere(int valor);

    // Remove o elemento do início da fila e retorna o valor removido.
    // Retorna -1 se a fila estiver vazia.
    int remove();
};

#endif // FILASEQ_H
