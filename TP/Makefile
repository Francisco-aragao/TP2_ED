#
# Copyright 2021 Alysson Ribeiro da Silva - Federal University of Minas Gerais
#
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the "Software"), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
# of the Software, and to permit persons to whom the Software is furnished to do 
# so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

# cc and flags
CC = g++
CXXFLAGS = -std=c++11 -g -Wall
DEBUG = -g
#CXXFLAGS = -std=c++11 -O3 -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# all sources, objs, and header files
MAIN = Main
TARGET = run.out
TARGET_DEBUG = debug.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*

debug:
	$(CC) $(DEBUG) -g -o $(BIN_FOLDER)$(TARGET_DEBUG) $(OBJ)

recursaoLOG:
	./bin/run.out -v 1 -s 10 -i entradaLOG.txt -o saidaRec.txt -p -l
	rm -rf graficos/recursaoGraficos
	mkdir graficos/recursaoGraficos
	cp log.out graficos/recursaoGraficos
	./mem/analisamem -i graficos/recursaoGraficos/log.out -p graficos/recursaoGraficos/saida
	gnuplot graficos/recursaoGraficos/*gp

recursao:
	./bin/run.out -v 1 -s 10 -i entrada.txt -o saidaRec.txt

mediana3LOG:
	./bin/run.out -v 2 -k 3 -s 10 -i entradaLOG.txt -o saidaMed.txt -p -l
	rm -rf graficos/mediana3Graficos
	mkdir graficos/mediana3Graficos
	cp log.out graficos/mediana3Graficos
	./mem/analisamem -i graficos/mediana3Graficos/log.out -p graficos/mediana3Graficos/saida
	gnuplot graficos/mediana3Graficos/*gp

mediana3:
	./bin/run.out -v 2 -k 3 -s 10 -i entrada.txt -o saidaMed3.txt

mediana5LOG:
	./bin/run.out -v 2 -k 5 -s 10 -i entradaLOG.txt -o saidaMed.txt -p -l
	rm -rf graficos/mediana5Graficos
	mkdir graficos/mediana5Graficos
	cp log.out graficos/mediana5Graficos
	./mem/analisamem -i graficos/mediana5Graficos/log.out -p graficos/mediana5Graficos/saida
	gnuplot graficos/mediana5Graficos/*gp

mediana5:
	./bin/run.out -v 2 -k 5 -s 10 -i entrada.txt -o saidaMed5.txt

mediana7LOG:
	./bin/run.out -v 2 -k 7 -s 10 -i entradaLOG.txt -o saidaMed.txt -p -l
	rm -rf graficos/mediana7Graficos
	mkdir graficos/mediana7Graficos
	cp log.out graficos/mediana7Graficos
	./mem/analisamem -i graficos/mediana7Graficos/log.out -p graficos/mediana7Graficos/saida
	gnuplot graficos/mediana7Graficos/*gp

mediana7:
	./bin/run.out -v 2 -k 7 -s 10 -i entrada.txt -o saidaMed7.txt

selection10LOG:
	./bin/run.out -v 3 -m 10 -s 10 -i entradaLOG.txt -o saidaSel.txt -p -l
	rm -rf graficos/selection10Graficos
	mkdir graficos/selection10Graficos
	cp log.out graficos/selection10Graficos
	./mem/analisamem -i graficos/selection10Graficos/log.out -p graficos/selection10Graficos/saida
	gnuplot graficos/selection10Graficos/*gp

selection10:
	./bin/run.out -v 3 -m 10 -s 10 -i entrada.txt -o saidaSel10.txt 

selection100LOG:
	./bin/run.out -v 3 -m 100 -s 10 -i entradaLOG.txt -o saidaSel.txt -p -l
	rm -rf graficos/selection100Graficos
	mkdir graficos/selection100Graficos
	cp log.out graficos/selection100Graficos
	./mem/analisamem -i graficos/selection100Graficos/log.out -p graficos/selection100Graficos/saida
	gnuplot graficos/selection100Graficos/*gp

selection100:
	./bin/run.out -v 3 -m 100 -s 10 -i entrada.txt -o saidaSel100.txt 

nRecursivoLOG:
	./bin/run.out -v 4 -s 10 -i entradaLOG.txt -o saidaNRec.txt -p -l
	rm -rf graficos/naoRecursivoGraficos
	mkdir graficos/naoRecursivoGraficos
	cp log.out graficos/naoRecursivoGraficos
	./mem/analisamem -i graficos/naoRecursivoGraficos/log.out -p graficos/naoRecursivoGraficos/saida
	gnuplot graficos/naoRecursivoGraficos/*gp

nRecursivo:
	./bin/run.out -v 4 -s 10 -i entrada.txt -o saidaNRec.txt 

empilhaIntLOG:
	./bin/run.out -v 5 -s 10 -i entradaLOG.txt -o saidaEmpInt.txt -p -l
	rm -rf graficos/empilhaInteligenteGraficos
	mkdir graficos/empilhaInteligenteGraficos
	cp log.out graficos/empilhaInteligenteGraficos
	./mem/analisamem -i graficos/empilhaInteligenteGraficos/log.out -p graficos/empilhaInteligenteGraficos/saida
	gnuplot graficos/empilhaInteligenteGraficos/*gp

empilhaInt:
	./bin/run.out -v 5 -s 10 -i entrada.txt -o saidaEmpInt.txt

heapLOG:
	./bin/run.out -v 6 -s 10 -i entradaLOG.txt -o saidaHeap.txt -p -l
	rm -rf graficos/heapGraficos
	mkdir graficos/heapGraficos
	cp log.out graficos/heapGraficos
	./mem/analisamem -i graficos/heapGraficos/log.out -p graficos/heapGraficos/saida
	gnuplot graficos/heapGraficos/*gp

heap:
	./bin/run.out -v 6 -s 10 -i entrada.txt -o saidaHeap.txt

mergeLOG:
	./bin/run.out -v 7 -s 10 -i entradaLOG.txt -o saidaMerge.txt -p -l
	rm -rf graficos/mergeGraficos
	mkdir graficos/mergeGraficos
	cp log.out graficos/mergeGraficos
	./mem/analisamem -i graficos/mergeGraficos/log.out -p graficos/mergeGraficos/saida
	gnuplot graficos/mergeGraficos/*gp

merge:
	./bin/run.out -v 7 -s 10 -i entrada.txt -o saidaMerge.txt

