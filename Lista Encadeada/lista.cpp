#include "lista.h"

Lista::Lista() : cabeca(nullptr), tamanho(0) { }

bool Lista::isVazia(){
    return (tamanho == 0);
}

int Lista::getTamanho(){
    return tamanho;
}

int Lista::elemento(int pos){
    if(isVazia() || pos < 1 || pos > tamanho)
        return -1;
    
    No* aux = cabeca;
    int cont = 1;
    while(cont < pos){
        aux = aux->getProximo();
        cont++;
    }
    return aux->getConteudo();
}

int Lista::posicao(int dado){
    No* aux = cabeca;
    int cont = 1;
    while(aux != nullptr){
        if(aux->getConteudo() == dado){
            return cont;
        }		
        aux = aux->getProximo();
        cont++;
    }
    return -1;
}

bool Lista::insere(int pos, int dado){
    if(isVazia() && pos != 1)
        return false;
    
    if(pos == 1)
        return insereInicio(dado);
    else if(pos == tamanho + 1)
        return insereFim(dado);
    else
        return insereMeioLista(pos, dado);
}

bool Lista::insereInicio(int valor){
    No* novoNo = new No();
    novoNo->setConteudo(valor);
    novoNo->setProximo(cabeca);
    cabeca = novoNo;
    tamanho++;
    return true;
}

bool Lista::insereMeioLista(int pos, int dado){
    if(pos < 1 || pos > tamanho + 1)
        return false;
    
    No* novoNo = new No();
    novoNo->setConteudo(dado);

    No* aux = cabeca;
    int cont = 1;
    while(cont < pos - 1){
        aux = aux->getProximo();
        cont++;
    }
    novoNo->setProximo(aux->getProximo());
    aux->setProximo(novoNo);
    tamanho++;
    return true;
}

bool Lista::insereFim(int dado){
    No* novoNo = new No();
    novoNo->setConteudo(dado);
    novoNo->setProximo(nullptr);
    
    if(isVazia()){
        cabeca = novoNo;
    } else {
        No* aux = cabeca;
        while(aux->getProximo() != nullptr){
            aux = aux->getProximo();
        }
        aux->setProximo(novoNo);
    }
    tamanho++;
    return true;
}

int Lista::remove(int pos){
    if(isVazia() || pos < 1 || pos > tamanho)
        return -1;
    
    if(pos == 1)
        return removeInicio();
    else
        return removeMeioLista(pos);
}

int Lista::removeInicio(){
    if(isVazia())
        return -1;
    
    No* p = cabeca;
    int dado = p->getConteudo();

    cabeca = p->getProximo();
    delete p;
    tamanho--;
    return dado;
}

int Lista::removeMeioLista(int pos){
    if(pos < 1 || pos > tamanho)
        return -1;
    
    No* atual = cabeca;
    No* antecessor = nullptr;
    int cont = 1;
    
    while(cont < pos && atual != nullptr){
        antecessor = atual;
        atual = atual->getProximo();
        cont++;
    }

    if(atual == nullptr)
        return -1;
    
    int dado = atual->getConteudo();
    antecessor->setProximo(atual->getProximo());
    delete atual;
    tamanho--;
    return dado;
}
