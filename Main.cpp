#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

#include "Rotor.h"
#include "Plugboard.h"
#include "Enigma_Machine.h"

Enigma_Machine *machine;

//Creates a new Enigma machine with the supplied plugboards and rotors
void configure(int argc, char **argv) {
	if(argc == 0) {
		//invalid
	} else if(argc == 1) {
		//no plugboard or rotors
	} else if(argc == 2) {
		//no  rotors
	} else {
		//First argument is plugboard, rest are rotors
	}
}

//Encode takes a given char and passes it to the machine, then returns the ouput
char encode(char c) {
  return c;
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
	configure(argc, argv);
	char curr_char;

	while(cin >> curr_char) {
    // encode that character, then output it
		if(valid(curr_char)) {
			cout << encode(curr_char);
		}
	}
	return 0;
}



