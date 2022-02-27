#include <iostream>
#include <string>
using namespace std;
#include "Logistic.h"

Logistic::Logistic() {}

Logistic::Logistic(string n, string d, int h, int m) {
	name = n;
	dest = d;
	hour = h;
	min = m;
}

string Logistic::getName() {
	return name;
}

void Logistic::setName(string n) {
	name = n;
}

string Logistic::getDest() {
	return dest;
}

void Logistic::setDest(string d) {
	dest = d;
}


int Logistic::getHour() {
	return hour;
}

void Logistic::setHour(int h) {
	hour = h;
}
int Logistic::getMin() {
	return min;
}

void Logistic::setMin(int m) {
	min = m;
}

void Logistic::showLogistic() {
	cout << name << " " << dest << " " << hour << "" << min << endl;
}
