GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary

$(PROGRAMA): Diario.o App.o Data.o Tempo.o ObterDataTempo.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Diario.o App.o Data.o Tempo.o ObterDataTempo.o main.o

main.o: main.cpp
	$(GCC) $(GCC_FLAGS) -c main.cpp

Diario.o: Diario.cpp
	$(GCC) $(GCC_FLAGS) -c Diario.cpp

App.o: App.cpp
	$(GCC) $(GCC_FLAGS) -c App.cpp	

Data.o: Data.cpp
	$(GCC) $(GCC_FLAGS) -c Data.cpp	

Tempo.o: Tempo.cpp
	$(GCC) $(GCC_FLAGS) -c Tempo.cpp	

ObterDataTempo.o: ObterDataTempo.cpp
	$(GCC) $(GCC_FLAGS) -c ObterDataTempo.cpp
