#ifndef Funcoes_h
#define Funcoes_h

#include "Registro.hpp"
#include "memlog.hpp"
#include "Pilha.hpp"

class Funcoes {
    private:
        //Funcoes auxiliares 

        //Cria partição menor para ser ordenada
        void Particao(int *i, int *j, Registro pivo, Registro *A, int *copias, int *comparacoes);
        //troca valor i por valor j
        void Troca(Registro *registros, int i, int j, int *copias);
        //Funcao que faz o merge no merge Sort
        void Merge(Registro *registros, int esq, int pivo, int dir, int *copias, int *comparacoes);
        //Funcao que cria o heap (arvore ordenada)
        void Heap(Registro *registros, int n, int meio, int *copias, int *comparacoes);
   
    public:
        int numerosAleatorios (int semente);
        void QuickSortRecursivo(Registro *registros, int esq, int dir, int *copias, int *comparacoes);
        void QuickSortMediana(Registro *registros, int esq, int dir, int k, int *copias, int *comparacoes);
        void QuickSortSelection(Registro *registros, int esq, int dir, int m, int *copias, int *comparacoes);
        void Selection(Registro *registros, int esq, int dir, int *copias, int *comparacoes);
        void QuickSortNaoRecursivo(Registro *registros, int esq, int dir, int *copias, int *comparacoes);
        void QuickSortEmpilhaInteligente(Registro *registros, int esq, int dir, int *copias, int *comparacoes);

        void MergeSort(Registro *registros, int esq, int dir, int *copias, int *comparacoes);
        
        void HeapSort(Registro *registros , int n, int *copias, int *comparacoes);      

};

#endif