#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_


class Plugboard {
public:
	Plugboard(int[]);
	virtual ~Plugboard();
	int use(int);
private:
	int plugs[26];
};



#endif /* PLUGBOARD_H_ */
