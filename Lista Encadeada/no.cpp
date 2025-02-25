#include "no.h"

No::No(){this->proximo = nullptr;}

int No::getConteudo(){return conteudo;}

void No::setConteudo(int cont){this->conteudo = cont;}

No* No::getProximo(){return proximo;}

void No::setProximo(No *prox){this->proximo = prox;}
