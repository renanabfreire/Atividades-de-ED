#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<long long> obterLista(char* instancia)
{
    ifstream inLista(instancia, ios::in);
    string linha;
    vector<long long> lista;

    while( !inLista.eof() )
    {
        inLista >> linha;
        lista.push_back(stoll(linha));
    }

    lista.pop_back();

    return lista;
}