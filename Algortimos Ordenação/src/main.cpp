#include "obterLista.cpp"
#include "sort.cpp"
#include <iostream>
#include <chrono>

int main(int argc, char** argv)
{
    vector<long long> list = obterLista(argv[1]);
    int tam = list.size();

    vector<long long> insert;
    vector<long long> selection;

    auto inicio = chrono::high_resolution_clock::now();
    
    insert = insertSort(list, tam);
    
    auto resultado = chrono::high_resolution_clock::now() -inicio;
    float seconds = chrono::duration_cast<chrono::milliseconds>(resultado).count();
    cout << "Tempo InsertionSort: " << float(seconds/1000) << endl;
    
    inicio = chrono::high_resolution_clock::now();

    selection = selectionSort(list, tam);

    resultado = chrono::high_resolution_clock::now() -inicio;
    seconds = chrono::duration_cast<chrono::milliseconds>(resultado).count();
    cout << "Tempo InsertionSort: " << float(seconds/1000) << endl;

    return 0;
}