#include "../include/Registro.hpp"

int Registro::getChave() {
    return this->chave;
}

void Registro::setChave(int chave) {
    this->chave = chave;
}

int* Registro::getEnderecoChave() {
    return &chave;
}


