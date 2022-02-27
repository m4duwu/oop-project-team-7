#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "Logistic.h" //parent
#include "vehicle.h" //child
#include "Commuter.h" //child
#include "schedule.h"

//Global variables for vector
//vector<Logistic>& llist;
vector<vehicle> vv;
vector<vehicle> vvtemp;
vector<vehicle> vvtemp1;
vector<Commuter> vc;
vector<Commuter> vctemp;
vector<Commuter> vctemp1;
vector<schedule> vs;
vector<schedule> vs3;
vector<schedule> vs4;
//vector<Logistic> vl;
//Shared Global Variables
string vn;
string dt;
string temp;
int cp;
int hr;
int mn;

string line;//to get string for each line of file
string path;//store path given by user to string
//default file path for COMMUTERS -> "C:\Users\haziq\source\repos\OOP Project Team 7\OOP Project Team 7\Data\commuter.txt"
//dafault file path for VEHICLES -> "C:\Users\haziq\source\repos\OOP Project Team 7\OOP Project Team 7\Data\vehicle.txt"

//function to get vehicle path from user

void vehiclePath();
void commuterPath();
bool check_number(string str);
void changeMenu();
int menu();
bool compareVehicleDestMaxCap(vehicle v1, vehicle v2);
bool compareTime(int vehicleTime, int commuterTime);
bool compareCommuterDestTime(Commuter c1, Commuter c2);
vector<schedule> generateSchedule(vector<vehicle>& vvv, vector<Commuter>& vcc);



int main() {
	while (1) {
		vehiclePath();
		commuterPath();


		changeMenu();

		//generate schedule here
		sort(vc.begin(), vc.end(), compareCommuterDestTime);
		vs3 = generateSchedule(vv, vc);
		sort(vvtemp1.begin(), vvtemp1.end(), compareVehicleDestMaxCap);
		vs4 = generateSchedule(vvtemp1, vctemp1);

		//erase members from vehicle and commuter

		for (size_t y = 0; y < vv.size(); y++)
		{
			if (vv.at(y).getCap() == 0)
				vv.erase(vv.begin() + y);
		}

		//press any number key to return to main menu
		while (1) {
			//int input;
			//input = menu();
			//switch case
			switch (menu())
			{
			case 1: system("cls"); for (auto i : vvtemp)i.showVehicle(); break;
			case 2: system("cls"); for (auto i : vctemp)i.showCommuter(); break;
				//to add vehicles at full cap
			case 3: system("cls"); for (auto i : vs3)i.showSchedule(); break; //sort commuter, no need to sort vehicle
				//to add vehicles at full cap
			case 4: system("cls"); for (auto i : vs4)i.showSchedule(); break; //sort commuter and sort vehicle
			case 5: system("cls"); for (auto i : vv)i.showVehicle(); break;//to add if statement to not show the 0s
			case 6: system("cls"); for (auto i : vc)i.showCommuter(); break;//have problem with deleting
			case 7: system("cls"); for (auto i : vs4)i.showSchedule(); break;
			case 8: break; //print out  schedule plan
			case 9: break; //modify vehicle
			case 10: break; 

			case -1: exit(0); break;
			default: system("cls"); cout << "please use valid input!\n" << endl; cin.clear(); cin.ignore(1000, '\n'); break; //cin.clear and cin.ignore is used to put the stream back into a good state and nd remove the bad input remaining in the input buffer. without this, there will be an infinite loop bug
			}
			changeMenu();

		}


		vc.clear();
		vv.clear();//clear vector list after each program run
	}
}

//function to get vehicle path from user
void vehiclePath() {
	while (1) {
		//get user input for file path
		cout << "Enter folder/path-name for available Vehicles (Press Enter For Default)\n" << ">";
		getline(cin, path); //use getline instead of cin so that WHITESPACES are included
		if (path == "") //check if userinput is blank or not (basically checking for enter)
			path = "C:\\Users\\haziq\\source\\repos\\OOP Project Team 7\\OOP Project Team 7\\Data\\vehicle.txt"; //setting vehicle path to default


		//++++++TO-DO++++++ Implement error for commuter path as vehicle and commuter have different data
		//////// check whether path is for vehicle or commuter 
		//////// idea- check for the last word before the 'txt' to see if its vehicle or commuter
		/////// Can be done on a later date


			//open file using path given
		ifstream file(path);
		if (file.is_open())
		{
			//going through file line by line
			while (getline(file, line)) {

				//store file details into vehicle object
				stringstream sstream(line);
				getline(sstream, vn, ' ');
				getline(sstream, temp, ' ');
				cp = stoi(temp);
				getline(sstream, dt, ' ');
				getline(sstream, temp, ':');
				hr = stoi(temp);
				getline(sstream, temp, ':');
				mn = stoi(temp);

				vehicle v(vn, dt, cp, hr, mn);
				vehicle vtemp(vn, dt, cp, hr, mn);
				vehicle vtemp1(vn, dt, cp, hr, mn);
				vv.push_back(v); //adding object into vector list
				vvtemp.push_back(vtemp);
				vvtemp1.push_back(vtemp1);

			}
			file.close();
			break;
		}
		else cout << "Unable to open file" << endl;

	}
	//vv.clear();//clear vector list after each program run
	//vv.remove("V04");
	//vv.showVehicle();
}

//function to get commuter path from user
void commuterPath() {
	while (1) {
		//get user input for file path
		cout << "Enter folder/path-name for available Commuters (Press Enter For Default)\n" << ">";
		getline(cin, path); //use getline instead of cin so that WHITESPACES are included
		if (path == "") //check if userinput is blank or not (basically checking for enter)
			path = "C:\\Users\\haziq\\source\\repos\\OOP Project Team 7\\OOP Project Team 7\\Data\\commuter.txt"; //setting vehicle path to default


		//++++++TO-DO++++++ Implement error for commuter path as vehicle and commuter have different data
		//////// check whether path is for vehicle or commuter 
		//////// idea- check for the last word before the 'txt' to see if its vehicle or commuter
		/////// Can be done on a later date


			//open file using path given
		ifstream file(path);
		if (file.is_open())
		{
			//going through file line by line
			while (getline(file, line)) {

				//store file details into vehicle object
				stringstream sstream(line);
				getline(sstream, vn, ' ');
				getline(sstream, dt, ' ');
				getline(sstream, temp, ':');
				hr = stoi(temp);
				getline(sstream, temp, ':');
				mn = stoi(temp);

				Commuter c(vn, dt, hr, mn);
				Commuter ctemp(vn, dt, hr, mn);
				Commuter ctemp1(vn, dt, hr, mn);
				vc.push_back(c); //adding object into vector list
				vctemp.push_back(ctemp);
				vctemp1.push_back(ctemp1);
			}
			file.close();
			break;
		}
		else cout << "Unable to open file" << endl;
	}
	//vc.showCommuter();
	//vv.clear();//clear vector list after each program run
	//vv.remove("V04");
	//vv.showVehicle();
}

bool check_number(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

void changeMenu() {
	while (1) {
		cout << "Enter any number key to return to main menu: " << "\n>";
		cin >> temp;
		if (check_number(temp))
			break;//cout << temp << "proceed to main menu" << endl;
		else
			cout << "enter number please" << endl;
	}
	system("cls"); // clear console to display clean menu
}

int menu() {
	int x;
	//checking for user input if correct or not (MUST BE INT)
	cout << "MAIN MENU:" << endl;
	cout << "1.  Display all vehicles" << endl;
	cout << "2.  Display all commuters" << endl;
	cout << "3.  Schedule commuters by arrival time" << endl;
	cout << "4.  Schedule commuters by minimum vehicles" << endl;
	cout << "5.  Display vehicles that is under capacity" << endl;
	cout << "6.  Display remaining commuters" << endl;
	cout << "7.  Display scheduling plan" << endl;
	cout << "8.  Save scheduling plan" << endl;
	cout << "9.  Modify vehicle list" << endl;
	cout << "10. Modify commuter list" << endl;
	cout << "\nKey -1 To End Program" << endl;

	cout << "\nPlase enter your option" << "\n>";
	cin >> x;
	return x;
}

bool compareVehicleDestMaxCap(vehicle v1, vehicle v2)
{
	if (v1.getDest() != v2.getDest())
		return (v1.getDest() < v2.getDest());
	return (v1.getCap() > v2.getCap());
}

bool compareTime(int vehicleTime, int commuterTime) //for scheduling
{
	bool status = false;
	int totalMinutes = 0;

	int vehicleHour = vehicleTime / 100;        //get hour
	int vehicleMinute = vehicleTime % 100;    //get min

	int commuterHour = commuterTime / 100;        //get hour
	int commuterMinute = commuterTime % 100;    //get min

	// Difference Between Times IN minutes
	if (commuterHour >= vehicleHour)     //look for earlier vehicle
	{
		totalMinutes = ((commuterHour * 60) + commuterMinute) - ((vehicleHour * 60) + vehicleMinute);        //Total = commuterTime - vehicleTime (in minutes)

		if ((totalMinutes >= 0) && (totalMinutes <= 30))                 //check grace time range only 0 to 30
		{
			status = true;
		}
	}

	return status;
}

bool compareCommuterDestTime(Commuter c1, Commuter c2)
{
	if (c1.getDest() != c2.getDest())
		return (c1.getDest() < c2.getDest());
	return (c1.getDest() < c2.getDest());
}

vector<schedule> generateSchedule(vector<vehicle>& vvv, vector<Commuter>& vcc) {
	vector<schedule> sched;
	int z = 0;
	for (int x = 0; x < vcc.size(); ++x)
	{
		for (int y = 0; y < vvv.size(); y++)
		{

			if (vvv.at(y).getDest() == vcc.at(x).getDest())
			{

				//check for time
				//get total minutes (time in minutes)
				int vtime = vvv.at(y).getHour() * 60 + vvv.at(y).getMin();
				int ctime = vcc.at(x).getHour() * 60 + vcc.at(x).getMin();
				//edit the variable to create the schedule object
				//sort variables later
				int totaltime = ctime - vtime;

				if (totaltime >= 0 && totaltime <= 30)
				{
					//- the vehicle capacity by 1
					if (vvv.at(y).getCap() > 0)
					{
						//vehicle newv(veh.getVname(), veh.getDest(), veh.getCap() - 1, veh.getHour(), veh.getMin());
						schedule s(++z, vvv.at(y), vcc.at(x));
						vcc.at(x).showCommuter();
						sched.push_back(s);
						//vcc.erase(vcc.begin() + x);
						//cout << c << endl;
						vvv.at(y).setCap(vvv.at(y).getCap() - 1);

						//vs.push_back(s);
						break;//dont need to check for other vehicle as commuter is already assigned a vehicle
					}
				}
			}
		}
	}
	return sched;
}