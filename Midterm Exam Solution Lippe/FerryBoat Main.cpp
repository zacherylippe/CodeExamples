//FILE : Main CommuterTrain.cpp
//PROG : Zachery Lippe
//PURP : Train Sim!
#include <iostream>
#include <string>
using namespace std;
#include "FerryBoat Header.h"

int main()
{
	FerryBoat myFerry(2, 20, 1, 0, 0); 
	myFerry.setAutosPortA(100, 75);
	myFerry.setAutosPortB(150, 100);
	cout << "All aboard the Summerville Express (Boats are slow! Ha ha!) Ferry!\n";
	myFerry.setCurrentPort(1);
	myFerry.SetDestination(2);
	myFerry.loadPax();		
	while(myFerry.getAutos(2) > 0)
	{
		myFerry.moveFerry(2);
		myFerry.unloadPax();
		myFerry.loadPax();
		myFerry.moveFerry(1);
		myFerry.unloadPax();
		myFerry.loadPax();
	}
	if(myFerry.getCurPort() != 1)
		myFerry.moveFerry(1);
	return 0;
}