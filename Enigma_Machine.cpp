#include<list>
using namespace std;

#include "Enigma_Machine.h"
#include "Plugboard.h"
#include "Rotor.h"

Enigma_Machine::Enigma_Machine( list<Rotor> rotors, Plugboard *plugboard) {
	if (rotors == NULL) {
		has_rotors = false;
	} else {
		this->rotors = rotors;
	}
	if (plugboard == NULL) {
			has_plugboard = false;
		} else {
			this->plugboard = rotors;
		}
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
