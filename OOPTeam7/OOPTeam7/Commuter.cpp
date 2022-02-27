#include <iostream>
#include <string>
using namespace std;
#include "Logistic.h"
#include "Commuter.h"

Commuter::Commuter() {}
Commuter::Commuter(string cn, string d, int h, int m)
{
	name = cn;
	dest = d;
	hour = h;
	min = m;
}

void Commuter::showCommuter() {
	if (min == 0)
	cout << name << " " << dest << " " << hour << ":0" << min << endl;
	else
	cout << name << " " << dest << " " << hour << ":" << min << endl;
}