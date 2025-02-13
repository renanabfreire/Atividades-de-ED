#ifndef LISTA__SEQUENCIAL
#define LISTA__SEQUENCIAL

class ListaSequencial
{
    private:
        int tam_atual = 0;
        int tam_lista = 100;
        int lista[256];
    
    public:
        ListaSequencial();
        ListaSequencial(int);
        ~ListaSequencial();

        bool estaVazia();
        bool estaCheia();
        int listaTamanho();
        int obterItem(int);
        int modificaValor(int, int);
        bool insereElemento(int, int);
        int removeElemento(int);
};

#endif // LISTA__SEQUENCIAL