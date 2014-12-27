#include<fstream>
#include<iostream>
using namespace std;

#include "Plugboard.h"

Plugboard::Plugboard(char* filename) {
	//Fill the array of plugs with an identity mapping
	for(int i=0;i<26;i++) {
		plugs[i] = i;
	}
	cout << "Got to here \n";
	//Then, for each pair of plugs in the plugboard, map them to each other
	int first;
	int second;
	fstream pbstream;
	cout << "Got to here \n";
	pbstream.open(filename, fstream::in | fstream::out);
	cout << "Opened file " << filename << "\n";

	/*while(!pbstream.eof()) { //Error somewhere in here
		cout << "Reading \n";
		pbstream >> first;
		cout << "First thing: " << first << "\n";
		pbstream >> second;
		cout << "Second thing: " << second << "\n";
		if(0 < first < 127 && 0 < second < 127) {
			cout << "I'm in ur if statement, savin ur data";
			plugs[first] = second;
			plugs[second] = first;
		}
		cout << "End of loop! \n";
	}
	cout << "Finished loop \n";
	*/
}

Plugboard::~Plugboard() {
	//TODO: EXTERMINATE
}

int Plugboard::use (int i) {
	return plugs[i];
}
