#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Rotor.h"

Rotor::Rotor(char* filename) {
	offset = 0;
	//Fill the array numbersf with the values from the .rot file
	int counter =0;
	fstream rstream;
	rstream.open(filename, fstream::in | fstream::out);
	if(rstream.fail()) {
			throw invalid_argument("The specified rotor does not exist.");
		}
	int curr_int;

	while(rstream >> curr_int) {
		numbersf[counter] = curr_int;
		if(rtesting) cout << "Numbersf[" << counter << "] = "
							<< numbersf[counter] << "\n";
		counter++;
	}

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
	if(rtesting) cout << "After applying rotor forwards, " << i << " becomes "
						<< numbersf[(i+offset)%26] << "\n";
	return (numbersf[(i+offset)%26] - offset + 26)%26;
}

int Rotor::use_backwards(int i) {
	if(rtesting) cout << "After applying rotor backwards, " << i << " becomes "
						<< (numbersb[(i + offset)%26]- offset + 26)%26 << "\n";
	return ((numbersb[(i + offset)%26] + 26) - offset)%26;
}

