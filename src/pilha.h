/*
 * pilha.h
 *
 *  Created on: Apr 30, 2012
 *      Author: rsjoao
 */

#ifndef PILHA_H_
#define PILHA_H_

#include <iostream>

//*********************************************************
template <typename Tipo>
class Pilha{
	public:
		Pilha();
		~Pilha();
		void empilha(const Tipo &elem);
		Tipo desempilha();
		bool vazia();
		int tamanho();
	private:
		struct Celula{
			Tipo num;
			Celula *prox;
		};
		Celula *topo;
		int nelem;
};
//*********************************************************
template <typename Tipo>
Pilha<Tipo>::Pilha(){
	topo = NULL ;
	nelem = 0;
}
//*********************************************************
template <typename Tipo>
Pilha<Tipo>::~Pilha(){
	Celula *aux;
	while(topo){
		topo = topo->prox;
		delete aux;
	}
}
//*********************************************************
template <typename Tipo>
void Pilha<Tipo>::empilha(const Tipo &elem){
	Celula *aux = new Celula;
	if(aux == NULL){ }
	aux->num = elem;
	aux->prox=topo;
	topo=aux;
	nelem++;
}
//*********************************************************
template <typename Tipo>
Tipo Pilha<Tipo>::desempilha(){
	Celula *aux = topo;
	Tipo ret = topo->num;
	topo = topo->prox;
	delete aux;
	nelem--;
	return (ret);
}
//*********************************************************
template <typename Tipo>
bool Pilha<Tipo>::vazia(){
	if(nelem==0){
		return 1;
	}
	return 0;
}
//*********************************************************
template <typename Tipo>
int Pilha<Tipo>::tamanho(){
	return (nelem);
}
#endif /* PILHA_H_ */
