//============================================================================
// Name        : projetoAAED.cpp
// Author(s)   : Renato Stoffalette Joao  renatosjoao@gmail.com
//			   :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ordenacao.h"

#define  NSEEDS 6


using namespace std;





int *iniVetor(int semente, int tamanho){
	int i, *v;
	v = new int[tamanho];
	srand(semente);
	for(i=0; i < tamanho; i++){
			v[i] = rand();
	}
	return v;
}



int main(int argc, char **argv) {
	ofstream myfile;
	struct timeval inicio, final;
	double tmili, elapsed_seconds, elapsed_useconds, elapsed_utime;
	struct timeval startTime;
	struct timeval endTime;
	int tamanhos;
	int semente;
	int *vetor;
	int seeds[NSEEDS] = {4, 81, 151, 1601, 2307, 4207};
    int vetores[9]	= {10000, 30000, 90000, 270000, 810000, 2430000, 7290000, 21870000, 65610000};


    myfile.open ("Relatorio.txt");
    myfile << "Trabalho final Análise de Algoritmos e Estruturas de Dados.\n";

for(tamanhos=0; tamanhos < 9; tamanhos++){
	for(semente=0; semente < 6; semente++){

		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação BUBBLESORT para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::bubbleSort(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

		cout <<" BUBBLE " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;

		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação INSERTSORT para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::insertSort(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

		cout <<" INSERT " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;


		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação SELECTSORT para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::selectSort(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" SELECT " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;



		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação QUICKSORT NAO RECURSIVA para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::quickSortNonRec(vetor,0,vetores[tamanhos]-1);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" QUICK " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;


		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação HEAPSORT para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::heapSort(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" HEAP " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;



		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação MERGESORT para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::mergeSort(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" MERGE " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;


		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação SHELLSORT  [ SHELL ] para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::shellSortShell(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" SHELL " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;


		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação SHELLSORT  [ KNUTH ] para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::shellSortKnuth(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;



		cout <<" KNUTH " << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;


		vetor = iniVetor(seeds[semente],vetores[tamanhos]);
		myfile <<"\nOrdenação SHELLSORT  [ PARDONS ] para um vetor de " << vetores[tamanhos] << " elementos." << endl;
		myfile << "Semente = " << seeds[semente] << endl;
		myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		gettimeofday(&inicio, NULL);
		ED::Ordenacao<int>::shellSortPardons(vetor,vetores[tamanhos]);
		gettimeofday(&final, NULL);
		tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
		myfile <<"Após ordenação ..."<< vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
		myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


		cout <<" PARDONS" << endl;
		cout <<"Semente = " << seeds[semente] << endl;
		cout <<"Tamanho = " << vetores[tamanhos] << endl;

	}
}
    myfile.close();




/*** Segunda parte do trabalho.
 * Criando um vetor aleatorio com 50.000 elementos
 *
 */

    myfile.open ("RelatorioII.txt");
    myfile << "Tempos de ordenação de um vetor inversamente ordenado com 50000 elementos.\n";

    vetor = iniVetor(4,50000);
    ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
    myfile <<"\nOrdenação BUBBLESORT." << endl;
    myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
    gettimeofday(&inicio, NULL);
    ED::Ordenacao<int>::bubbleSort(vetor,50000);
    gettimeofday(&final, NULL);
    tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
    myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

    vetor = iniVetor(4,50000);
    ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
    myfile <<"\nOrdenação INSERTSORT." << endl;
    myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
    gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::insertSort(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação SELECTSORT." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::selectSort(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação QUICKSORT Não Recursiva." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::quickSortNonRec(vetor,0,49999);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação HEAPSORT." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::heapSort(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação MERGESORT." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::mergeSort(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação SHELLSORT [SHELL]." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::shellSortShell(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação SHELLSORT [KNUTH]." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::shellSortKnuth(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;

	vetor = iniVetor(4,50000);
	ED::Ordenacao<int>::inverteVetor(vetor,50000); //ordenando inversamente os elementos do vetor
	myfile <<"\nOrdenação SHELLSORT [PARDONS]." << endl;
	myfile << "Antes da ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	gettimeofday(&inicio, NULL);
	ED::Ordenacao<int>::shellSortPardons(vetor,50000);
	gettimeofday(&final, NULL);
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	myfile << "Apos ordenação ..." << vetor[0] << ", " << vetor[1] << ", " << vetor[2] << ", " << vetor[3] << ", ..." << endl;
	myfile << "\n Tempo decorrido em  milisegundos = " <<  tmili << endl;


	myfile.close();

	return 0;
}
