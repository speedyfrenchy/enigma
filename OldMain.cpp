#include <stdexcept>
#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include <algorithm>
using namespace std;

#include "Rotor.h"
#include "Plugboard.h"

list<*Rotor> rotors;
Plugboard *plugboard;

//given the name of a .pb file, will configure the plugboard.
void configure_plugboard(char* board_name) {
	plugboard = new Plugboard(board_name);
}

//given the name of a .rot file, will configure a single rotor and add it to the list
void configure_rotor(char* rotor_name) {
	//TEST THIS
  Rotor *new_rotor = new Rotor(rotor_name);
  rotors.push_back(new_rotor);
}

//configure takes the command line arguments and sets up the rotors/plugboards accordingly
void configure(int argc, char **argv) {
  //FOR TESTING
  cout << "Arguments: " << argc << "\n";
  if(argc == 0) 
    throw invalid_argument("How did you even manage to do this?");
  else if(argc == 1)
    configure_plugboard((char*)"plugboards/null.pb"); //given no rotors or plugboards, configure with a null plugboard
  else if(argc == 2)
    configure_plugboard(argv[1]);
  else {
    configure_plugboard(argv[argc-1]);
    for(int i =1; i < argc-1; i++) {
      //configure_rotor(argv[i]);
    	cout << "configuring rotor " << i ;
    }
  }
}

//rotates the rotors, cascading the rotations if necessary
void rotate_rotors() {
	list<Rotor>::iterator rot_iter = rotors.begin();
	bool cascade = rot_iter->rotate();
	//If we need to cascade and we're not on the last rotor:
	while(cascade && rot_iter != rotors.end()) {
		rot_iter++;
		cascade = (rot_iter)->rotate();
	}
	//If we need to cascade and we're on the end rotor
	if(cascade && rot_iter == rotors.end()) {
		rot_iter ->rotate();
	}
}

//Given the int to encode, applies the effects of the rotors
int use_rotors(int i) {
	//First pass out to the reflector
	for(list<Rotor>::iterator rotors_iter = rotors.begin();
			rotors_iter != rotors.end();
			rotors_iter++) {
		//Apply the effects of the current rotor
		i = rotors_iter->use_forwards(i);
	}
	i = reflect(i);
	//Second pass back from the reflector
		for(list<Rotor>::iterator rotors_iter = rotors.end();
				rotors_iter != rotors.begin();
				rotors_iter--) {
			//Apply the effects of the current rotor
			i = rotors_iter->use_backwards(i);
		}
	//Once all the rotor's effects have been applied
	rotate_rotors();
	return i;
}

//reflect applies the reflector
int reflect(int i) {
  return (i+13)%26;
}

//encode takes a character and encodes it using the rotors and plugboards
char encode(char c) {
  //Convert the ASCII char to an int
  int i = c - 65;

  i = plugboard->use(i);
  i = use_rotors(i);

  return (char)i + 65;
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

int main(int argc, char **argv)
{
  configure(argc, argv);
  char curr_char;
  //while standard input stream is open
  
    //read a character
    cin >> curr_char; //Probably not the way I'm meant to do it...
    // encode that character, then output it
    if(valid(curr_char)) {
      cout << encode(curr_char);
    }
    
    //FOR TESTING (wait for input)
    cin >> curr_char;
  return 0;
}
