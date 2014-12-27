#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Plugboard.h"

Plugboard::Plugboard(int plugs [26]) {
	this->plugs = plugs;
}

Plugboard::~Plugboard() {
	//TODO: EXTERMINATE
}

int Plugboard::use (int i) {
	return plugs[i];
}
