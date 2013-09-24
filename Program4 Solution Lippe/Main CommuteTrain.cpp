//FILE : Main CommuterTrain.cpp
//PROG : Zachery Lippe
//PURP : Train Sim!
#include <iostream>
#include <string>
using namespace std;
#include "Class CommuterTrain.h"

int main()
{
	CommuterTrain myTrain(30, 200, 1); //30 (the first one) is the totalStations vars, change it if you want a different number of stations. Why have a pointless const vars?
	cout << "All aboard the Summerville Express Train!\n";
	myTrain.SetDestination(30);
	int dest = myTrain.getDestination();
	myTrain.loadPax();
	for (int ct = 1; ct < dest; ++ct)
	{
		myTrain.moveTrain(myTrain.getCurStation()+1);
		myTrain.unloadPax();
		myTrain.loadPax();
	}
	myTrain.moveTrain(1);
	myTrain.unloadPax();
	return 0;
}