#include <iostream>
#include "lista__sequencial.hpp"

using namespace std;

int main()
{
    ListaSequencial lista_exemplo = ListaSequencial(100);

    if(lista_exemplo.estaVazia())
        cout << "Está vazia!" << endl;
    else
        cout << "Não está vazia" << endl;


    for(int i=1; i<=100; i++)
        lista_exemplo.insereElemento(i, i);
    
    if(lista_exemplo.estaCheia())
        cout << "Encheu!" << endl;
    else
        cout << "Não está cheia!" << endl;

    cout << lista_exemplo.listaTamanho() << endl;

    cout << lista_exemplo.obterItem(50) << endl;

    lista_exemplo.modificaValor(101, 50);

    cout << lista_exemplo.obterItem(50) << endl;

    for(int i=1; i<=100; i++)
        lista_exemplo.removeElemento(1);
    
    if(lista_exemplo.estaVazia())
        cout << "Está vazia!" << endl;
    else
        cout << "Não está vazia" << endl;

    return 0;
}