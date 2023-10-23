#ifndef Pilha_h
#define Pilha_h

#include "NoPilha.hpp"

class Pilha {
    private:
        NoPilha *topo = nullptr;
    public: 
        void Empilha (Item item);
        Item Desempilha ();
        NoPilha* getTopo();
};

#endif