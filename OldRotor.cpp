#include <fstream>
using namespace std;

#include "Rotor.h"

Rotor::Rotor(char* filename) {
	offset = 0;
	//Fill the array of numbers with the values from the .rot file
	int counter =0;
	fstream rstream;
	rstream.open(filename, fstream::in | fstream::out);
	while(!rstream.eof()) {
		rstream >> numbers[counter];
		counter++;
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
	return numbers[(i+offset)%26];
}

int Rotor::use_backwards(int i) {
	int j;
	for(int k = 0; k < 26; k++) {
		if(numbers[k] == i) {
			j = k;
		}
	}
	return j;
}

