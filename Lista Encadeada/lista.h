#ifndef LISTA_H
#define LISTA_H
#include "no.h"

class Lista{
	private:
		No* cabeca;
		int tamanho;
	public:
		Lista();
		bool isVazia();
		int getTamanho();
		int elemento(int pos);
		int posicao(int dado);
		bool insere(int pos, int dado);
		bool insereInicio(int valor);
		bool insereMeioLista(int pos, int dado);
		bool insereFim(int dado);
		int remove(int pos);
		int removeInicio();
		int removeMeioLista(int pos);
};

#endif // LISTA_H
