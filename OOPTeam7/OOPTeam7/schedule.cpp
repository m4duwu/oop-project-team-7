#include <iostream>
#include <string>
using namespace std;
#include "Commuter.h"
#include "vehicle.h"

#include "schedule.h"


schedule::schedule() {}
schedule::schedule(int i, vehicle vc, Commuter cm)
{
	id = i;
	v = vc;
	c = cm;
}
//schedule will store schedule id and information of vehicle and commuter



void schedule::showSchedule() {
	if (v.getMin() == 0)
		cout << id << " " << v.getName() << " " << v.getDest() << " " << v.getHour() << ":0" << v.getMin() << " " << v.getCap() << " " << c.getName() << " " << " " << c.getDest() << " " << c.getHour() << ":" << c.getMin() << endl;
	else if (c.getMin() == 0)
		cout << id << " " << v.getName() << " " << v.getDest() << " " << v.getHour() << ":" << v.getMin() << " " << v.getCap() << " " << c.getName() << " " << " " << c.getDest() << " " << c.getHour() << ":0" << c.getMin() << endl;
	else if ((v.getMin() == 0) && (c.getMin() == 0))
		cout << id << " " << v.getName() << " " << v.getDest() << " " << v.getHour() << ":0" << v.getMin() << " " << v.getCap() << " " << c.getName() << " " << " " << c.getDest() << " " << c.getHour() << ":0" << c.getMin() << endl;
	else
		cout << id << " " << v.getName() << " " << v.getDest() << " " << v.getHour() << ":" << v.getMin() << " " << v.getCap() << " " << c.getName() << " " << " " << c.getDest() << " " << c.getHour() << ":" << c.getMin() << endl;


	//v.showVehicle();
	//c.showCommuter();
}