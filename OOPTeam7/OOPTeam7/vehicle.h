#ifndef _H_VEHICLE
#define _H_VEHICLE
#include "Logistic.h"
class vehicle :
    public Logistic
{
    int cap;
public:
    vehicle();
    vehicle(string, string, int, int, int);

    int getCap();
    void setCap(int);
    void showVehicle();
};
#endif
