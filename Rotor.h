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
	int numbers_f [26]; // Mapping going forwards
	int numbers_b [26]; // Mapping going backwards
	int offset;
};

#endif /* ROTOR_H_ */
