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

void Enigma_Machine::rotate_rotors() {
	list<Rotor>::iterator rotors_iter = rotors.begin();
	//Rotate the first rotor
	bool cascade = rotors_iter->rotate();
	//If we need to cascade and we're not on the last rotor:
	while(cascade && rotors_iter != rotors.end()) {
		rotors_iter++;
		cascade = (rotors_iter)->rotate();
	}
	//If we need to cascade and we're on the end rotor
	if(cascade && rotors_iter == rotors.end()) {
		rotors_iter ->rotate();
	}
}

int Enigma_Machine::use(int i) {
	if (has_plugboard) {
		i = plugboard->use(i);
	}
	list<Rotor>::iterator rotors_iter;
	if (has_rotors) {
		//First pass out to the reflector
		for(rotors_iter = rotors.begin();
				rotors_iter != rotors.end();
				rotors_iter++) {
				//Apply the effects of the current rotor
				i = rotors_iter->use_forwards(i);
		}
	}
	i = use_reflector(i);
	if (has_rotors) {
		//Second pass back from the reflector
		for(rotors_iter = rotors.end();
				rotors_iter != rotors.begin();) {
				rotors_iter--;
				//Apply the effects of the current rotor
				i = rotors_iter->use_backwards(i);
		}
		//Once all the rotor's effects have been applied
		rotate_rotors();
	}
	if (has_plugboard) {
			i = plugboard->use(i);
		}
	return i;
}

Enigma_Machine::~Enigma_Machine() {
	//Destructor
}
