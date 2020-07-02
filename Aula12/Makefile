GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = diary

$(PROGRAMA): Diario.o App.o Data.o Tempo.o ObterDataTempo.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Diario.o App.o Data.o Tempo.o ObterDataTempo.o main.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diario.o: src/Diario.cpp
	$(GCC) $(GCC_FLAGS) -c src/Diario.cpp

App.o: src/App.cpp
	$(GCC) $(GCC_FLAGS) -c src/App.cpp	

Data.o: src/Data.cpp
	$(GCC) $(GCC_FLAGS) -c src/Data.cpp	

Tempo.o: src/Tempo.cpp
	$(GCC) $(GCC_FLAGS) -c src/Tempo.cpp	

ObterDataTempo.o: src/ObterDataTempo.cpp
	$(GCC) $(GCC_FLAGS) -c src/ObterDataTempo.cpp

clean:
	rm -f *.o 
	rm $(PROGRAMA)
