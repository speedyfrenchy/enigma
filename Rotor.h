#ifndef ROTOR_H_
#define ROTOR_H_

class Rotor {
public:
	Rotor(char*);
	virtual ~Rotor();
	int use_forwards(int);
	int use_backwards(int);
	bool rotate();
private:
	int numbers [26];
	int offset;
};

#endif /* ROTOR_H_ */
