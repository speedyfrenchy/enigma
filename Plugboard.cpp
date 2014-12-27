#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Plugboard.h"

Plugboard::Plugboard(char* filename) {
	//Fill the array of plugs with an identity mapping
	for(int i=0;i<26;i++) {
		plugs[i] = i;
	}
	//Then, for each pair of plugs in the plugboard, map them to each other
	int first = -1;  // Null values can cause problems,
	int second = -1; //  So initialised to -1
	fstream pbstream;
	pbstream.open(filename);
	if(pbstream.fail()) { // If the file didn't open properly
		throw invalid_argument("The specified plugboard does not exist.");
	}

	while(pbstream >> first) {
		pbstream >> second;

		if((0 < first) && (first < 127) && (0 < second) && (second < 127) ) {
			plugs[first] = second;
			plugs[second] = first;
		}
	}
}

Plugboard::~Plugboard() {
	//TODO: EXTERMINATE
}

int Plugboard::use (int i) {
	return plugs[i];
}
