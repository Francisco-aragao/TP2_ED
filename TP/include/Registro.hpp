#ifndef Registro_h
#define Registro_h

#include <iostream>

class Registro {
    public:
        int chave;
        char palavras[15][200];
        float numeros[10];
    public:
        int getChave();
        void setChave(int chave);
        int* getEnderecoChave();
};

#endif