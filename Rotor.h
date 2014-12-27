#ifndef ROTOR_H_
#define ROTOR_H_

class Rotor {
public:
	Rotor(int[]);
	virtual ~Rotor();
	int use_forwards(int);
	int use_backwards(int);
	bool rotate();
private:
	int numbersf [26]; // Mapping going forwards
	int numbersb [26]; // Mapping going backwards
	int offset;
};

#endif /* ROTOR_H_ */
