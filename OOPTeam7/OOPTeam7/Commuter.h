#ifndef _H_COMMUTER
#define _H_COMMUTER
#include "Logistic.h"
class Commuter :
    public Logistic
{
public:
	//constructor
	Commuter();
	Commuter(string, string, int, int);

	void showCommuter();
};
#endif
