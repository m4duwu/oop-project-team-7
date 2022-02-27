#ifndef _H_LOGISTIC
#define _H_LOGISTIC
class Logistic
{
protected:
	string name;
	string dest;
	int hour;
	int min;

public:
	Logistic();
	Logistic(string, string, int, int);

	string getName();
	void setName(string);
	string getDest();
	void setDest(string);
	int getHour();
	void setHour(int);
	int getMin();
	void setMin(int);

	void showLogistic();
};
#endif
