//FILE : FerryBoat Header.h
//PROG : Zachery Lippe
//PURP : Train Simulation!

#include <iostream>
using namespace std;									
#include <ctime>
class FerryBoat
{
	private:
		int maxCapacity;
		int numOnBoard;	
		int curPort;			
		int totalPorts;							
		int destination;
		int carsPortA;
		int carsPortB;

	public:
		FerryBoat(int, int, int, int, int);
		int getMaxCapacity();
		int getNumOnBoard();
		int getCurPort();
		int getTotalPorts();
		int getDestination();
		void loadPax();
		void unloadPax();
		void SetDestination(int);
		void moveFerry(int);
		void setCurrentPort(int);
		int genRandNumberFromRange(int, int);
		int setAutosPortA(int, int);
		int setAutosPortB(int, int);
		int getAutos(int);
};
FerryBoat::FerryBoat(int numStops, int maxCap, int start, int autosPortA, int autosPortB)
{
	totalPorts = numStops;
	maxCapacity = maxCap;
	curPort = start;
	numOnBoard = 0;	
	carsPortA = autosPortA;
	carsPortB = autosPortB;

	srand ((unsigned)time(NULL));
}

int FerryBoat::getMaxCapacity()
{
	return maxCapacity;
}

int FerryBoat::getNumOnBoard()
{
	return numOnBoard;
}

int FerryBoat::getCurPort()
{
	return curPort;
}

int FerryBoat::getTotalPorts()
{
	return totalPorts;
}

int FerryBoat::getDestination()
{
	return destination;
}

void FerryBoat::loadPax()
{
	int autosWaiting;
	if(curPort == 1)
	{
		autosWaiting = carsPortA;
		cout<<"There are "<<autosWaiting<<" cars waiting to get on the ferry at port A."<<endl;
		if(autosWaiting > maxCapacity)
			carsPortA -= maxCapacity;
		else
			carsPortA = 0;
	}
	else
	{
		autosWaiting = carsPortB;
		cout<<"There are "<<autosWaiting<<" cars waiting to get on the ferry at port B."<<endl;
		if(autosWaiting > maxCapacity)
			carsPortB -= maxCapacity;
		else
			carsPortB = 0;
	}
	if(autosWaiting > maxCapacity)
	{
		cout<<"Sorry, not everyone can get on the ferry!"<<endl;
		numOnBoard = maxCapacity;
		cout<<"Loading finished, full vehicle capacity of "<<maxCapacity<<" on board!"<<endl;
	}
	else
	{
		numOnBoard+=autosWaiting;
		cout<<"Loading finished, vehicle capacity of "<<numOnBoard<<" on board!"<<endl;
	}
}

void FerryBoat::unloadPax()
{
	cout<<numOnBoard<<" have gotten off the ferry!"<<endl;
	numOnBoard = 0;
}

void FerryBoat::SetDestination(int dest)
{
	destination=dest;
}

void FerryBoat::moveFerry(int nextPort)
{
	destination = nextPort;
	if(curPort == 1)
	{
		cout << "Leaving Port A for Port B with "<< numOnBoard  <<" vehicles."<<endl;
		cout<<"Arriving at port B!"<<endl;
		curPort = destination;
	}
	else
	{
		cout << "Leaving Port B for Port A with "<< numOnBoard  <<" vehicles."<<endl;
		cout<<"Arriving at port A!"<<endl;
		curPort = destination;
	}
}

void FerryBoat::setCurrentPort(int setcurPort)
{
	curPort = setcurPort;
}

int FerryBoat::genRandNumberFromRange(int maxNum, int minNum)
{
	return (rand() % (maxNum - minNum +1) + minNum);
}
int FerryBoat::setAutosPortA(int max, int min)
{
	carsPortA = genRandNumberFromRange(max, min);
	return carsPortA;
}
int FerryBoat::setAutosPortB(int max, int min)
{
	carsPortB = genRandNumberFromRange(max, min);
	return carsPortB;
}
int FerryBoat::getAutos(int portNum)
{
	if(portNum==1)
		return carsPortA;
	else
		return carsPortB;
}