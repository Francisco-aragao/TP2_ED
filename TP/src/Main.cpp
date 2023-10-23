#include <iostream>
#include <string.h>
#include <fstream>
#include <sys/resource.h>

#include "../include/msgassert.hpp"
#include "../include/Funcoes.hpp"
#include "../include/memlog.hpp"

using std::string;

int main (int argc, char* argv[]) {
   
    // Declaro variáveis de medição do tempo
    struct rusage resources;
    int rc;
    double utimeInicio, stimeInicio, utimeFim, stimeFim, total_time;

    // ------------------ Verificações dos parâmetros de entrada ----------------------

    erroAssert(argc >= 8, "Não informado a quantiadade de parâmetros necessários"); 
    erroAssert(strcmp(argv[1], "-v") == 0, "Não informado variação do algoritmo"); 
    
    int variacaoEscolhida = 0;
    for (int i = 1; i <= 7; i++) {  // leio variação do algoritmo a ser utilizada
        if (argv[2] == std::to_string(i)) {
            variacaoEscolhida = i;
            break;
        }
    }
    erroAssert(variacaoEscolhida != 0, "Não informado valor correto da variação do algoritmo");
    
    int k = 0; //vou ler valores necessarios para mediana ou tamanho da partição do quicksort
    int m = 0;
    int auxiliar = 2; //valor para fazer controle do argv quando tenho parametros a mais (mediana e selection)
    
    if (variacaoEscolhida == 2) {
        erroAssert(strcmp(argv[3], "-k") == 0, "Não informado calculo da mediana");  
        k = std::atoi(argv[4]);
        auxiliar = 0;
        erroAssert(k != 0, "Não informado valor para calculo da mediana");  
    }
    if (variacaoEscolhida == 3) {
        erroAssert(strcmp(argv[3], "-m") == 0, "Não informado particao do vetor");  
        m = std::atoi(argv[4]);
        auxiliar = 0;
        erroAssert(m != 0, "Não informado valor para tamanho da partição");  
    }

    erroAssert(strcmp(argv[5 - auxiliar], "-s") == 0, "Não informada semente para gerar numeros aleatorios");  
    
    int semente = 0; //leio semente
    semente = std::atoi(argv[6 - auxiliar]);
    erroAssert(semente != 0, "Não informado valor para semente");  

    erroAssert(strcmp(argv[7 - auxiliar], "-i") == 0, "Não informado arquivo de entrada");  
    string nomeArquivoEntrada = "";    //leio arquivo de entrada
    nomeArquivoEntrada = argv[8 - auxiliar];    
    erroAssert(nomeArquivoEntrada != "", "Não informado nome arquivo entrada");  

    erroAssert(strcmp(argv[9 - auxiliar], "-o") == 0, "Não informado arquivo de saida");  
    string nomeArquivoSaida = "";   //leio arquivo saida
    nomeArquivoSaida = argv[10 - auxiliar];    
    erroAssert(nomeArquivoSaida != "", "Não informado nome arquivo saida");  

    bool iniciaMem = false;     //Faço controle das funcoes do memlog
    bool ativaMem = false;
    if (argc >= 12 - auxiliar) {
        if (strcmp(argv[11 - auxiliar], "-p") == 0) {
            iniciaMemLog((char*)"log.out");
            desativaMemLog();
            iniciaMem = true;
        } else {
            finalizaMemLog();
        }
    }
    if (iniciaMem == true && argc >= 13 - auxiliar) {
        if (strcmp(argv[12 - auxiliar], "-l") == 0) {
            ativaMemLog();
            ativaMem = true;
        } else {
            desativaMemLog();
        }
    }

    //abro os arquivos de entrada e saida
    std::ifstream arquivoEntrada;
    arquivoEntrada.open(nomeArquivoEntrada);
    erroAssert(arquivoEntrada.is_open() == true, "Erro abertura arquivo de entrada");  

    std::ofstream arquivoSaida;
    arquivoSaida.open(nomeArquivoSaida);
    erroAssert(arquivoSaida.is_open() == true, "Erro abertura arquivo de saida");  

    // ------------------ Fim da verificações dos parâmetros de entrada ----------------------


    // Declaro variaveis para controle do loop
    int n;
    int qtdValores;
    int indice = 0; // indice para vetores de copias e comparacoes
    arquivoEntrada >> qtdValores;

    //crio vetores para salvar movimentações e copias (7 posicoes pois temos 7 valores difernetes de entrada)
    int copias[qtdValores];
    int comparacoes[qtdValores];
    
    while (indice < qtdValores ) { //Executo algoritmo pela quantidade de valores da entrada
        
        int mult = 1;  //parametro para alterar a seed para o calculo da média
        
        arquivoEntrada >> n;
        arquivoSaida << "Entrada N: " << n << "\n";

        unsigned long int mediaCopias = 0.0;
        unsigned long int mediaComparacoes = 0.0;
        double mediaTempo = 0.0;

        for (int it = 0; it < 5; it++ ) { //loop que é executado 5 vezes para calcular a média de cada algoritmo
            
            if (ativaMem == true) it = 4; //condicao para utilizar memlog apenas uma vez caso seja ativado
            
            for (int i = 0; i < qtdValores; i++) { //inicializo valores 
                copias[i] = comparacoes[i] = 0;
            }

            // ------------ Medição do tempo inicial ----------
            if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                perror("getrusage failed");
            }
            utimeInicio = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
            
            stimeInicio = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
            // ------------ Medição do tempo inicial ----------

            Registro *registros = new Registro [n];
            srand(semente * mult); //defino a semente
            
            Funcoes funcoes;
            for (int i = 0; i < n; i++) { //chaves recebendo valores aleatorios
                registros[i].setChave(funcoes.numerosAleatorios(semente)); 
            }

            std::cout << "N: " << n << "\n"; //imprimo valores que estão sendo ordenados
            switch (variacaoEscolhida) {
                case 1: 
                    funcoes.QuickSortRecursivo(registros, 0, n-1, &copias[indice], &comparacoes[indice]);
                break;
                
                case 2:
                    funcoes.QuickSortMediana(registros, 0, n-1, k, &copias[indice], &comparacoes[indice]);
                break;
                case 3:
                    funcoes.QuickSortSelection(registros, 0, n-1, m, &copias[indice], &comparacoes[indice]);
                break;
                case 4:
                    funcoes.QuickSortNaoRecursivo(registros, 0, n-1, &copias[indice], &comparacoes[indice]);
                break;
                case 5:
                    funcoes.QuickSortEmpilhaInteligente(registros, 0, n-1, &copias[indice], &comparacoes[indice]);
                break;
                case 6:
                    funcoes.HeapSort(registros, n, &copias[indice], &comparacoes[indice]);
                break;
                case 7:
                    funcoes.MergeSort(registros, 0, n-1, &copias[indice], &comparacoes[indice]);
                break;
            }
    
            delete [] registros; 

            // ------------ Medição do tempo final ----------
            if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
            perror("getrusage failed");
            }
            utimeFim = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
            
            stimeFim = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
            total_time = (utimeFim - utimeInicio) + (stimeFim - stimeInicio);
            // ------------ Medição do tempo final ----------

            // imprimo métricas de tempo para cada n, suas copias e comparacoes além de informações da semente no arquivo de saída
            arquivoSaida << "Semente: " << semente * mult << " Tempo Usuário: " << utimeFim - utimeInicio << " Tempo Sistema: " << stimeFim - stimeInicio << " Tempo total: " << total_time << "\n";
            arquivoSaida << "Copias: " << copias[indice] << " Comparações: " << comparacoes[indice] << "\n\n";

            mult += 10; //incremento valor para alterar a semente para calculo da média de cada n

            mediaTempo+= total_time;
            mediaCopias += copias[indice];
            mediaComparacoes += comparacoes[indice];
        }
        //imprimo as médias no arquivo de saída
        arquivoSaida << "Media Copias: " << mediaCopias/5 << " Media Comparacoes: " << mediaComparacoes/5 << " Tempo medio: " << mediaTempo/5 << "\n\n";
        indice++;   // indice de controle do vetor de copias e comparacoes aumenta
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    if (ativaMem == true) desativaMemLog();
    if (iniciaMem == true) finalizaMemLog();

    return 0;
}