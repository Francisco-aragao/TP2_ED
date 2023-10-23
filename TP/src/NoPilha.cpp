#include "../include/NoPilha.hpp"

Item NoPilha::getItem() {
    return this->item;
}
 
NoPilha* NoPilha::getProx() {
    return this->prox;
}

void NoPilha::setItem(Item item) {
    this->item = item;
} 

void NoPilha::setProx(NoPilha *prox) {
    this->prox = prox;
}

int NoPilha::getDir() {
    return item.dir;
}

int NoPilha::getEsq() {
    return item.esq;
}

void NoPilha::setDir(int dir) {
    this->item.dir = dir;
}

void NoPilha::setEsq(int esq) {
    this->item.esq = esq;
}