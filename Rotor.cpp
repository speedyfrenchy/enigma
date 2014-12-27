#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Rotor.h"

Rotor::Rotor(int numbers [26]) {
	offset = 0;
	numbersf = numbers;

	//Now, using numbersf, create numbersb
	for(int i = 0; i < 26; i++) {
		numbersb[numbersf[i]] = i;
	}
}

Rotor::~Rotor() {
	//TODO: EXTERMINATE
}

//Return a flag indicating whether or not the rotation should be cascaded
bool Rotor::rotate() {
	if (offset < 25) {
	  offset++;
	  return false;
	}
	else {
		offset = 0;
		return true;
	}
}

int Rotor::use_forwards(int i) {
	return (numbersf[(i+offset)%26] - offset + 26)%26;
}

int Rotor::use_backwards(int i) {
	return ((numbersb[(i + offset)%26] + 26) - offset)%26;
}

