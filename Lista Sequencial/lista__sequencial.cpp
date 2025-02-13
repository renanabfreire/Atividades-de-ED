#include "lista__sequencial.hpp"

ListaSequencial::ListaSequencial()
{
}

ListaSequencial::ListaSequencial(int tamanho)
{
    tam_atual = 0;
    tam_lista = tamanho;
}

ListaSequencial::~ListaSequencial()
{
}

bool ListaSequencial::estaVazia()
{
    if(tam_atual == 0) return true;
    else return false;
}

bool ListaSequencial::estaCheia()
{
    if(tam_atual == tam_lista) return true;
    else return false;
}

int ListaSequencial::listaTamanho()
{
    return tam_atual;
}

int ListaSequencial::obterItem(int pos)
{
    if ((pos>tam_atual) || (pos<=0))
        return -1;

    return lista[pos-1];
}

int ListaSequencial::modificaValor(int dado, int pos)
{
    int dado_excluido;
    if ((pos > tam_atual) || (pos < 1))
        return -1;

    dado_excluido = lista[pos-1];
    lista[pos-1] = dado;

    return dado_excluido;
}

bool ListaSequencial::insereElemento(int dado, int pos)
{
    if(estaCheia() || (pos > tam_atual+1) || (pos<=0))
        return false;

    for (int i = tam_atual; i >=pos; i--)
        lista[i] = lista[i-1];

    lista[pos-1] = dado;
    tam_atual++;
    return true;
}

int ListaSequencial::removeElemento(int pos)
{
    int dado;
    if ((pos > tam_atual) || (pos < 1))
        return -1;

    dado = lista[pos-1];
    for(int i = pos-1; i < tam_atual-1; i++)
        lista[i] = lista[i+1];

    tam_atual--;
    return dado;
}
