#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

#include "Rotor.h"
#include "Plugboard.h"
#include "Enigma_Machine.h"

Enigma_Machine *machine;

//Creates a new plugboard from the supplied file
Plugboard configure_plugboard(char* filename) {
	int plugs [26];
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
		throw invalid_argument("The specified .pb file does not exist.");
	}
	while(pbstream >> first) {
		pbstream >> second;
		if((0 < first) && (first < 127) && (0 < second) && (second < 127) ) {
			plugs[first] = second;
			plugs[second] = first;
		}
	}
	return new Plugboard(plugs);
}

//Creates a new rotor from the supplied file
Rotor configure_rotor(char* filename) {
	int numbers [26];
	//Fill the array numbers with the values from the .rot file
	int counter =0;
	fstream rstream;
	rstream.open(filename, fstream::in | fstream::out);
	if(rstream.fail()) {
		throw invalid_argument("The specified .rot file does not exist.");
	}
	int curr_int;
	while(rstream >> curr_int) {
		numbers[counter] = curr_int;
		counter++;
	}
	return new Rotor(numbers);
}

//Creates a new Enigma machine from the supplied arguments
void configure_machine(int argc, char **argv) {
	if(argc == 0) {
		throw invalid_argument("Invalid Argument - must be of the form: enigma [rotors] [plugboard]");
	} else if(argc == 1) {
		machine = new Enigma_Machine(NULL, NULL);
	} else if(argc == 2) {
		Plugboard plugboard = configure_plugboard(argv[1]);
		machine = new Enigma_Machine(NULL, plugboard);
	} else {
		Plugboard plugboard = configure_plugboard(argv[argc-1]);
		Rotor *current_rotor;
		list<Rotor> rotors;

		for(int i =1; i < argc-1; i++) {
			current_rotor = configure_rotor(argv[i]);
			rotors.push_back(*current_rotor);
		}
		machine = new Enigma_Machine(rotors, plugboard);
	}
}

//Encode takes a given char and passes it to the machine, then returns the ouput
char encode(char c) {
	int i = c - 65;
	i = machine->use(i);
	return i + 65;
}

//valid checks if a character is allowed, ignored or disallowed.
bool valid(char c) {
  if(isupper(c))
    return true;
  else if(isspace(c))
    return false;
  else throw invalid_argument("Input must be an upper case character or whitespace");
    return false;
}

int main(int argc, char **argv) {
	configure_machine(argc, argv);

	char curr_char;
	while(cin >> curr_char) {
    // encode that character, then output it
		if(valid(curr_char)) {
			cout << encode(curr_char);
		}
	}
	return 0;
}



