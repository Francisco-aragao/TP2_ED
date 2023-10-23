#include "../include/Pilha.hpp"

void Pilha::Empilha(Item item) { //adiciono topo
    NoPilha *nova;
    nova = new NoPilha();
    nova->setItem(item);
    nova->setProx(topo);
    topo = nova;
}

Item Pilha::Desempilha() { //retiro topo
    NoPilha *p;
    Item aux;
    
    if(topo == nullptr) {
        throw "Erro\n";
    }

    aux = topo->getItem();
    p = topo;
    if (topo->getProx() == nullptr) {
         topo = nullptr;
    } else {
        topo = topo->getProx();
    }
    p = nullptr;
    delete p;
    return aux;
}

NoPilha* Pilha::getTopo() {
    return topo;
}