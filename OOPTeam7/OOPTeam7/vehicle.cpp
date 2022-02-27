#include <iostream>
#include <string>
using namespace std;
#include "Logistic.h"
#include "vehicle.h"

vehicle::vehicle() {}
vehicle::vehicle(string vn, string d, int c, int h, int m)
{
	name = vn;
	dest = d;
	cap = c;
	hour = h;
	min = m;
}

void vehicle::showVehicle() {
	if(min==0)
	cout << name << " " << cap << " " << dest << " " << hour << ":0" << min << endl;
	else
	cout << name << " " << cap << " " << dest << " " << hour << ":" << min << endl;
}

int vehicle::getCap() {
	return cap;
}

void vehicle::setCap(int c) {
	cap = c;
}


