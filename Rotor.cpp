#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Rotor.h"

Rotor::Rotor(int numbers [26]) {
	offset = 0;
	numbers_f = numbers;

	//Using numbersf, create numbersb
	for(int i = 0; i < 26; i++) {
		numbers_b[numbers_f[i]] = i;
	}
}

Rotor::~Rotor() {
}

//Rotate, then return a bool indicating whether or not the rotation should be cascaded
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
	return (numbers_f[(i+offset)%26] - offset + 26)%26;
}

int Rotor::use_backwards(int i) {
	return ((numbers_b[(i + offset)%26] + 26) - offset)%26;
}

