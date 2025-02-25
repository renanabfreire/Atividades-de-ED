#ifndef NO_H
#define NO_H

class No{
	private:
		int conteudo;
		No* proximo;
	public:
		No();
		int getConteudo();
		void setConteudo(int cont);
		No* getProximo();
		void setProximo(No* prox);
};

#endif // NO_H
