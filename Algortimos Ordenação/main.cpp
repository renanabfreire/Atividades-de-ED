#include "obterLista.cpp"
#include "sort.cpp"
#include <iostream>

int main(int argc, char** argv)
{
    vector<int> list = obterLista(argv[1]);

    cout << list.size() << endl;    
}