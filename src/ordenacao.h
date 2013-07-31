/*
 * ordenacao.h
 *
 *  Created on: Apr 29, 2012
 *      Author: rsjoao
 */

#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include "pilha.h"

namespace ED{

	template <typename T>

	class Ordenacao{

	public:
		static void bubbleSort(T *vetor, unsigned int tamanho);                        //bubbleSort
	    static void insertSort(T *vetor, int tamanho); 								   //insertSort
	    static void selectSort(T* vetor, unsigned int tamanho);                        //selectSort

	    static void inverteVetor(T* vetor, unsigned int tamanho); // metodo para inverter o vetor

		static void quickSortRec(T *vetor, int tamanho);  							     //quickSort
		static void quickSortNonRec(T *vetor, int start, int stop);						//quickSortNonRec
		static void heapSort(T *vetor, int tamanho); 									//heapSort
		static void mergeSort(T* vetor, int tamanho);  									//mergeSort

		static void shellSortShell(T *vetor, int tamanho);								//shellSort Shell
		static void shellSortKnuth(T *vetor, int tamanho);								//shellSortKnuth
		static void shellSortPardons(T *vetor, int tamanho);							//shellSortPardons

	private:
		static void heapify(T *vetor, int pai, int heapsize);							//heapfy
		static void build_heap(T *vetor, int tamanho);									//build_heap
		static void merge(T* vetor, int *aux, int esquerda,int meio, int direita);		//merge
		static void m_sort(T *vetor, int *aux, int esquerda, int direita);				//m_sort
		static int particiona(T *vetor, int start, int stop);							//particiona
	};


/**** inverteVetor *******************/
template<typename T>
void Ordenacao<T>::inverteVetor(T* vetor, unsigned int tamanho){
	int i,j,aux;
	for(i = tamanho - 1; i > 0; i--) {
	        for(j=0; j < i; j++) {
	            if(vetor[j+1] > vetor[j]) {
	                aux = vetor[j];
	                vetor[j]=vetor[j+1];
	                vetor[j+1]=aux;
	            }
	        }
	    }

}

/********* BUBBLESORT ***********/
template<typename T>
void Ordenacao<T>::bubbleSort(T *vetor, unsigned int tamanho) {
    int i,j,aux;
    for(i = tamanho - 1; i > 0; i--) {
        for(j=0; j < i; j++) {
            if(vetor[j+1] < vetor[j]) {
                aux = vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    }
}
/********* INSERTSORT ***********/
template <typename T>
void Ordenacao<T>::insertSort(T* vetor, int tamanho){
   int j,i,aux;
   for(i = 1; i < tamanho; i++){
      aux = vetor[i];
      j = i - 1;
      while(j >= 0 && vetor[j] > aux){
         vetor[j + 1] = vetor[j];
         j--;
      }
      vetor[j + 1] = aux;
   }
}
/********* SELECTSORT ***********/
template <typename T>
void Ordenacao<T>::selectSort(T* vetor, unsigned int tamanho){
  int i, j, imenor, swap ;
  for (i = 0; i < (tamanho -1); i++) {
    imenor = i;
    for (j = (i+1); j < tamanho; j++) {
      if(vetor[j] < vetor[imenor]) {
        imenor = j;
      }
    }
      swap = vetor[i];
      vetor[i] = vetor[imenor];
      vetor[imenor] = swap;
  }
}

/********QUICKSORT ******************/
template<typename T>
void Ordenacao<T>::quickSortRec(T* vetor, int tamanho){

	 if (tamanho < 2)
	        return;
	    int p = vetor[tamanho / 2];
	    int *l = vetor;
	    int *r = vetor + tamanho - 1;
	    while (l <= r) {
	        while (*l < p)
	            l++;
	        while (*r > p)
	            r--;
	        if (l <= r) {
	            int t = *l;
	            *l++ = *r;
	            *r-- = t;
	        }
	    }
	    quickSortRec(vetor, r - vetor + 1);
	    quickSortRec(l, vetor + tamanho - l);

	}

/******* QUICKSORT NON RECURSIVE *******************************/
template<typename T>
void Ordenacao<T>::quickSortNonRec(T *vetor, int start, int stop){
	int i;
	Pilha<int> *p = new Pilha<int>();
	p->empilha(start);
	p->empilha(stop);

	while(!p->vazia()){
		stop = p->desempilha();
		start = p->desempilha();
		if (stop <= start){
			continue;
		}
		i = particiona(vetor, start, stop);
		if((i - start) > (stop - i)){
			p->empilha(start);
			p->empilha(i-1);
		}
		p->empilha(i+1);
		p->empilha(stop);
		if((stop - i) >= (i - start)){
			p->empilha(start);
			p->empilha(i-1);
		}
	}
}
/********PARTICIONA ******************/
template<typename T>
int Ordenacao<T>::particiona(T* vetor, int start, int stop){
	  int a, down, temp, up,pj;
	        a=vetor[start];
	        up=stop;
	        down=start;
	        while(down<up)
	        {
	            while(vetor[down]<=a && down<up)
	                down=down+1;
	            while(vetor[up]>a)
	                up=up-1;

	            if(down<up)
	            {
	                temp=vetor[down];
	                vetor[down]=vetor[up];
	                vetor[up]=temp;
	            }
	        }
	        vetor[start]=vetor[up];
	        vetor[up]=a;
	        pj=up;
	        return (pj);
}

/******** HEAPSORT ************/
template<typename T>
void Ordenacao<T>::heapSort(T *vetor, int tamanho){
    int i;
    build_heap(vetor,tamanho);
    for(i=tamanho-1; i > 0; i--) {
    	std::swap(vetor[0], vetor[i]);
    	heapify(vetor, 0, i);
    }
}
/*********HEAPIFY ***********/
template<typename T>
void Ordenacao<T>::heapify(T *vetor, int pai, int heapsize)
{
     int fl, fr, imaior;
      while (true) {
    	 fl = (pai << 1) + 1;
    	 fr = fl + 1;
         if ((fl < heapsize) && (vetor[fl] > vetor[pai])){
        	 imaior = fl;
         }else{
        	 imaior = pai;
         }
         if ((fr < heapsize) && (vetor[fr] > vetor[imaior])){
        	 imaior = fr;
         }
         if (imaior != pai){
         std::swap(vetor[pai],vetor[imaior]);
         pai = imaior;
         }
         else  break;
     }
}
/***BUILD HEAP ******/
template<typename T>
void Ordenacao<T>::build_heap(T *vetor, int tamanho){
	int i;
	for (i=(tamanho>>1)-1; i>=0; i--)
	 heapify(vetor, i, tamanho);
}


/********MERGE************/
template <typename T>
void Ordenacao<T>::merge(T *vetor, int *aux, int esquerda, int meio, int direita) {
	int i, j, k;
	i = k = esquerda;
	j = meio+1;
	while((i <= meio) && (j <= direita)) {
		if(vetor[i] < vetor[j])
			aux[k++] = vetor[i++];
		else aux[k++] = vetor[j++];
	}
	while(i <= meio) aux[k++] = vetor[i++];
	while(j <= direita) aux[k++] = vetor[j++];
	while(esquerda <= direita) vetor[esquerda] = aux[esquerda++];
}

/******MERGESORT****************/
template<typename T>
void Ordenacao<T>::mergeSort(T *vetor, int tamanho) {
  int *aux = new int[tamanho];
  m_sort(vetor, aux , 0, tamanho - 1);
  delete aux;

}
/*****M_SORT*******************/
template<typename T>
void Ordenacao<T>::m_sort(T *vetor, int *aux, int esquerda, int direita){
	if(direita <= esquerda) return;
	int meio = (direita + esquerda) >> 1;
	m_sort(vetor, aux, esquerda, meio);
	m_sort(vetor, aux, meio+1, direita);
	merge(vetor, aux, esquerda, meio, direita);
}
/************* SHELLSORT ***********************/
template<typename T>
void Ordenacao<T>::shellSortShell(T* vetor, int tamanho){
	int i, j, h;
	int aux;
	h = tamanho;
	do{
		h /= 2;
		for(i = h; i < tamanho; i++){
			aux = vetor[i];
			j = i -h;
			while((j >= 0) && (aux < vetor[j])){
				vetor[j+h] = vetor[j];
				j -= h;
			}
			vetor[j+h] = aux;
		}
	}while(h!=1);
}


/************* SHELLSORT KNUTH *****************/
template<typename T>
void Ordenacao<T>::shellSortKnuth(T *vetor, int tamanho){
	int i, j, h, aux;
	h = 1;
 	do{
 		h = 3*h + 1;
 		}while(h < tamanho);
    do{
    	h /= 3;
    	for(i = h; i < tamanho; i++){
    		aux = vetor[i];
    		j = i -h;
    		while((j >= 0) && (aux < vetor[j])){
    			vetor[j+h] = vetor[j];
    			j -= h;
    			}
    		vetor[j+h] = aux;
    	}
    }while(h!=1);
}
/************* SHELLSORT PARDONS ******************/
template <typename T>
void Ordenacao<T>::shellSortPardons(T *vetor, int tamanho){
int i, j, h, aux, k=0;
int  increments[] = {217378076, 45806244, 9651787, 2034035, 428481, 90358, 19001, 4025, 836, 182, 34, 9, 1};
	while(increments[k]>tamanho)
		k++;
	do{
		h = increments[k++] ;
		for(i = h; i < tamanho; i++){
			aux = vetor[i];
			j = i -h;
			while((j >= 0) && (aux < vetor[j])){
				vetor[j+h] = vetor[j];
				j -= h;
			}
			vetor[j+h] = aux;
		}
	} while(h!=1);
}


}
#endif /* ORDENACAO_H_ */
