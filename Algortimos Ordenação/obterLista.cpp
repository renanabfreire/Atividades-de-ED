#include <fstream>
#include <vector>
using namespace std;

vector<int> obterLista(char* instancia)
{
    ifstream inLista(instancia, ios::in);
    string linha;
    vector<int> lista;

    while( !inLista.eof() )
    {
        inLista >> linha;
        lista.push_back(stoi(linha));
    }

    return lista;
}