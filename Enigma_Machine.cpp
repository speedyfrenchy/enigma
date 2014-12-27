#include<list>
using namespace std;

#include "Enigma_Machine.h"
#include "Plugboard.h"
#include "Rotor.h"

Enigma_Machine::Enigma_Machine( list<Rotor> rotors, Plugboard *plugboard) {
	this->rotors = rotors;
	this->plugboard = plugboard;
}

int Enigma_Machine::use_reflector(int i) {
	return (i+13)%26;
}

int Enigma_Machine::use(int i) {
	//TODO: Main encoding method
	return i;
}

Enigma_Machine::~Enigma_Machine() {
	//Destructor
}
