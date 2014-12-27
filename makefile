
enigma: Main.o Rotor.o Plugboard.o
	g++ -o enigma Main.o Rotor.o Plugboard.o


Main.o: Main.cpp Rotor.h Plugboard.h
	g++ -c Main.cpp 

Rotor.o: Rotor.cpp Rotor.h
	g++ -c Rotor.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -c Plugboard.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
