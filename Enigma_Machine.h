#ifndef ENIGMA_MACHINE_H_
#define ENIGMA_MACHINE_H_

class Enigma_Machine {
public:
	Enigma_Machine(list<Rotor> rotors, Plugboard *plugboard);
	virtual ~Enigma_Machine();
	int use(int);
private:
	int use_reflector(int);
	void rotate_rotors();
	bool has_plugboard = true;
	bool has_rotors = true;
	Plugboard *plugboard;
	list<Rotor> rotors;
};



#endif /* ENIGMA_MACHINE_H_ */
