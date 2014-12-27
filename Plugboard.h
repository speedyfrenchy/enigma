#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_


class Plugboard {
public:
	Plugboard(char*);
	virtual ~Plugboard();
	int use(int);
private:
	int plugs[26];
};



#endif /* PLUGBOARD_H_ */
