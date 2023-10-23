#ifndef NoPilha_h
#define NoPilha_h

#include "Registro.hpp"

class Item {
    public:
        int dir;
        int esq;
}; 

class NoPilha {
    private:
        NoPilha* prox = nullptr;
        Item item;

    public:
        Item getItem();
        NoPilha* getProx();
        void setItem(Item item);
        void setProx(NoPilha* prox);
        void setDir (int dir);
        void setEsq (int esq);
        int getDir();
        int getEsq();
};

#endif