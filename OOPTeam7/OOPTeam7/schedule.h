#ifndef _H_SCHEDULE
#define _H_SCHEDULE
#include "Logistic.h"
class schedule :
    public Logistic
{
	int id;
	vehicle v;
	Commuter c;

public:
	schedule();
	schedule(int, vehicle, Commuter);

	void showSchedule();
};
#endif

