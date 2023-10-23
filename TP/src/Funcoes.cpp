#include "../include/Funcoes.hpp"

int Funcoes::numerosAleatorios(int semente) {
    return rand(); // retorno numero aleatorio gerado
}

void Funcoes::Troca(Registro *registros, int i, int j, int *copias) {
    Registro aux = registros[i];
    LEMEMLOG((long int)(&(registros[i])), sizeof(Registro), 0);
    registros[i] = registros[j];
    LEMEMLOG((long int)(&(registros[j])), sizeof(Registro), 0);
    ESCREVEMEMLOG((long int)(&(registros[i])), sizeof(Registro), 0);
    registros[j] = aux;
    ESCREVEMEMLOG((long int)(&(registros[j])), sizeof(Registro), 0);
    *copias+=3; //são feitas 3 copias
}

// Faço comparações dos elementos em relação ao pivô e faço as trocas
void Funcoes::Particao(int *i, int *j, Registro pivo, Registro *registros, int *copias, int *comparacoes) {

    do {
        *comparacoes +=1; //comparacao quando entra no while
        while (pivo.getChave() > registros[*i].getChave()) { //ando até chave esquerda maior que pivo
            LEMEMLOG((long int)(&(registros[*i])), sizeof(Registro), 0);
            (*i)++;
            *comparacoes +=1;
        }
        *comparacoes +=1;
        while (pivo.getChave() < registros[*j].getChave()) { //ando até chave direita menor que pivo
            LEMEMLOG((long int)(&(registros[*j])), sizeof(Registro), 0);
            (*j)--;
            *comparacoes +=1;
        }
        *comparacoes+=1;
        if (*i <= *j) { //faço comparação para trocar
            Troca(registros, *i, *j, copias);
            (*i)++;
            (*j)--;
        }
        *comparacoes+=1;
    } while (*i <= *j);    

}

void Funcoes::QuickSortRecursivo (Registro *registros, int esq, int dir, int *copias, int *comparacoes) {
    
    int i = esq;
    int j = dir;

    Registro pivo;

    pivo = registros[(i + j) / 2]; // obtem o pivo  
    LEMEMLOG((long int)(&(registros[(i + j) / 2])), sizeof(Registro), 0);

    Particao (&i, &j, pivo, registros, copias, comparacoes);    // particiono e faço as trocas

    //faço chamadas recursivas
    if (esq < j) {
        QuickSortRecursivo(registros, esq, j, copias, comparacoes);
    }
    if (i < dir) {
        QuickSortRecursivo(registros, i, dir, copias, comparacoes);
    }
}


void Funcoes::QuickSortMediana (Registro *registros, int esq, int dir, int k, int *copias, int *comparacoes) {
    int i = esq;
    int j = dir;

    Registro pivo;

    int valores[k]; //pego k valores aleatorios para mediana entre limites do tamanho do registro
    int mediana;

    for (int i = 0; i < k; i++) {
        valores[i] = rand() % (dir - esq);
        if (valores[i] < esq) {
            valores[i] += esq;
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 1+i; j < k; j++) {
            if (valores[i] > valores[j]) {
                int aux = valores[j];
                valores[j] = valores[i];
                valores[i] = aux;
            }
        }
    }
    mediana = valores[(int) k/2];

    pivo = registros[mediana]; // obtem o pivo 
    LEMEMLOG((long int)(&(registros[mediana])), sizeof(int*), 0);

    Particao (&i, &j, pivo, registros, copias, comparacoes); // Particiono e faço as trocas

    //Faço as chamadas recursivas
    if (esq < j) {
        QuickSortMediana(registros, esq, j, k, copias, comparacoes);
    }
    if (i < dir) {
        QuickSortMediana(registros, i, dir, k, copias, comparacoes);
    }
} 

void Funcoes::Selection (Registro *registros, int esq, int dir, int *copias, int *comparacoes) {
    int min;

    for (int a = esq; a < dir; a++) {
        min = a;
        for (int b = a + 1 ; b <= dir; b++) {
            *comparacoes += 1;
            if (registros[b].chave < registros[min].chave) {
                LEMEMLOG((long int)(&(registros[b])), sizeof(Registro), 0);
                LEMEMLOG((long int)(&(registros[min])), sizeof(Registro), 0);
                min = b;
            }
        }
        Troca (registros, a, min, copias);
    }
}

void Funcoes::QuickSortSelection(Registro *registros, int esq, int dir, int m, int *copias, int *comparacoes) {
    int i = esq;
    int j = dir;

    
    if (j-i <= m) {  // Caso tamanho (j - i) for menor do que a partição m, utilizo o selection sort

        Selection(registros, esq, dir, copias, comparacoes);
        return;
    
    } else {
        Registro pivo;

        pivo = registros[(i + j) / 2]; // obtem o pivo 
        LEMEMLOG((long int)(&(registros[(i+j)/2])), sizeof(int*), 0);

        Particao(&i, &j, pivo, registros, copias, comparacoes); //Particiono e faço as trocas
    }

    //Faço chamadas recursivas
    if (esq < j) {
        QuickSortSelection(registros, esq, j, m, copias, comparacoes);
    }
    if (i < dir) {
        QuickSortSelection(registros, i, dir, m, copias, comparacoes);
    }
    
}



void Funcoes::QuickSortNaoRecursivo(Registro *registros, int esq, int dir, int *copias, int *comparacoes) {
    Pilha pilha;
    Item item; // Item possui campos esq e dir

    item.dir = (dir);   //item recebe particao atual e é empilhado
    item.esq = (esq);
    pilha.Empilha(item);

    do {
        if (dir > esq) {
            int i = esq;
            int j = dir;

            Registro pivo;

            pivo = registros[(i + j) / 2];
            LEMEMLOG((long int)(&(registros[(i + j) / 2])), sizeof(Registro), 0);

            Particao(&i, &j, pivo, registros, copias, comparacoes); //Particiono e faço as trocas

            if ((j-esq) > (dir-i)) {    //Verifico tamanho e empilho novos limites das partições
                item.esq = (i);
                item.dir = (dir);
                pilha.Empilha(item);
                dir = j;
            } else {
                item.dir = (j);
                item.esq = (esq);
                pilha.Empilha(item);
                esq = i;
            }
        } else {    // Ao finalizar desempilho particao
            item = pilha.Desempilha();
            dir = item.dir;
            esq = item.esq;
        } 
    } while (pilha.getTopo() != nullptr);
}  

void Funcoes::QuickSortEmpilhaInteligente(Registro *registros, int esq, int dir, int *copias, int *comparacoes) {
    Pilha pilha;
    Item item; // Item com campos esq e dir
 
    item.dir = (dir); //item recebe particao atual e é empilhado
    item.esq = (esq);
    pilha.Empilha(item);
    do {

        if (dir > esq) {

            int i = esq;
            int j = dir;

            Registro pivo;

            pivo = registros[(i + j) / 2];
            LEMEMLOG((long int)(&(registros[(i + j) / 2])), sizeof(Registro), 0);

            Particao(&i, &j, pivo, registros, copias, comparacoes); //Particiono e faço as trocas

            //Verifico menor partição primeiro
            if ((j-esq)>(dir-i)) { //Verifico tamanho e empilho novos limites das partições
                item.dir = (j);
                item.esq = (esq);
                pilha.Empilha(item);
                esq = i;
            } else {
                item.esq = (i);
                item.dir = (dir);
                pilha.Empilha(item);
                dir = j;
            }
        } else { 
            item = pilha.Desempilha();  // Ao finalizar desempilho particao
            dir = item.dir;
            esq = item.esq;
        } 
    } while (pilha.getTopo() != nullptr);
}  


void Funcoes::MergeSort(Registro *registros, int esq, int dir, int *copias, int *comparacoes) {
    int pivo;
    if(esq < dir) {
        pivo = esq+(dir-esq)/2; // pivo elemento do meio

        //Ordeno esquerda depois direita - ao final junto
        MergeSort(registros, esq, pivo, copias, comparacoes);
        MergeSort(registros, pivo+1, dir, copias, comparacoes);
        Merge(registros, esq, pivo, dir, copias, comparacoes);
    }
}


void Funcoes::Merge(Registro  *registros, int esq, int pivo, int dir, int *copias, int *comparacoes) {
    
    //Defino tamanho das particoes que serão criadas
    int tamPDir = dir - pivo;
    int tamPEsq = pivo - esq + 1;

    //Crio partiçoes e aloco dinamicamente
    Registro *particaoDir = new Registro[tamPDir];
    Registro *particaoEsq = new Registro[tamPEsq];

    //preencho ambas as partições com os elementos correspondentes
    for (int i = 0; i < tamPEsq; i++){
        particaoEsq[i] = registros[esq + i];
        LEMEMLOG((long int)(&(registros[esq + i])), sizeof(Registro), 0);
        *copias += 1;
    }

    for (int j = 0; j < tamPDir; j++) {
        particaoDir[j] = registros[pivo + 1 + j];
        LEMEMLOG((long int)(&(registros[pivo + 1 + j])), sizeof(Registro), 0);
        *copias += 1;
    }

    //Variaveis auxiliares para percorrer e comparar vetores
    int i = 0;
    int j = 0;
    int k = esq;

    //Seleciono o maior elemento de cada particao e salvo no vetor de Registros
    while (i < tamPEsq && j < tamPDir) {
        *comparacoes +=1;
        if (particaoEsq[i].getChave() <= particaoDir[j].getChave()) {
            registros[k] = (particaoEsq[i]);
            *copias += 1;
            ESCREVEMEMLOG((long int)(&(registros[k])), sizeof(Registro), 0);
            i++;
        } else {
            registros[k] = (particaoDir[j]);
            *copias += 1;
            ESCREVEMEMLOG((long int)(&(registros[k])), sizeof(Registro), 0);
            j++;
        }
        k++;
    }

    //Adiciono elementos que sobraram no vetor de registros para serem ordenados posteriormente
    while (i < tamPEsq) {
        registros[k] = (particaoEsq[i]);
        *copias += 1;
        ESCREVEMEMLOG((long int)(&(registros[k])), sizeof(Registro), 0);
        i++;
        k++;
    }

    while (j < tamPDir) {
        registros[k] = (particaoDir[j]);
        *copias += 1;
        ESCREVEMEMLOG((long int)(&(registros[k])), sizeof(Registro), 0);
        j++;
        k++;
    }
    delete [] particaoDir;
    delete [] particaoEsq;
}


void Funcoes::Heap(Registro *registros, int n, int raiz, int *copias, int *comparacoes) {
    
    //no direito é a posicao da raiz +2
    int dir = 2 * raiz + 2;
    
    //no esquerdo é a posicao da raiz +1
    int esq = 2 * raiz + 1;
     
    // Maior termo começa como raiz
    int maior = raiz;
 
    // Analiso condições para atualizar o maior
    *comparacoes += 1;
    if (esq < n && registros[esq].getChave() > registros[maior].getChave()) {
        LEMEMLOG((long int)(&(registros[esq])), sizeof(Registro), 0);
        LEMEMLOG((long int)(&(registros[maior])), sizeof(Registro), 0);
        maior = esq;
    }
    
    *comparacoes += 1;
    if (dir < n && registros[dir].getChave() > registros[maior].getChave()) {
        LEMEMLOG((long int)(&(registros[dir])), sizeof(Registro), 0);
        LEMEMLOG((long int)(&(registros[maior])), sizeof(Registro), 0);
        maior = dir;
    }
 
    // Caso maior não é mais a raiz novo maior vira raiz e reorganizo arvore (Funcao Heap)
    if (maior != raiz) {
        Troca(registros, raiz, maior, copias);
        Heap(registros, n, maior, copias, comparacoes);
    }
}
 
void Funcoes::HeapSort(Registro *registros, int n, int *copias, int *comparacoes) {
 
    //Começo criando heap (arvore com ordenação) - Defino raiz como elemento do meio
    for (int raiz = n / 2 - 1; raiz >= 0;  raiz--) {
        Heap(registros, n, raiz, copias, comparacoes);
    }

    //Faço retirada das raizes
    for (int i = n - 1; i > 0; i--) {
        // Mando raiz para o final
        Troca(registros, 0, i, copias);
        // Retiro a antiga raiz que agora está no final
        Heap(registros, i, 0, copias, comparacoes);
    }
}
