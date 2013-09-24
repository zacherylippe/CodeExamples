//FILE : Class CommuterTrain.h
//PROG : Zachery Lippe
//PURP : Train Simulation!

#include <iostream>
using namespace std;									
#include <ctime>					
class CommuterTrain
{
	private:
		int maxCapacity;
		int numOnBoard;	
		int curStation;			
		int totalStations;							
		int destination;			

	public:
		CommuterTrain(int, int, int);
		int getMaxCapacity();
		int getNumOnBoard();
		int getCurStation();
		int getTotalStations();
		int getDestination();
		void loadPax();
		void unloadPax();
		void SetDestination(int);
		void moveTrain(int);
		void setCurrentStation(int);
		int genRandNumber(int);
};
CommuterTrain::CommuterTrain(int numStops, int maxCap, int start)
{
	totalStations = numStops;
	maxCapacity = maxCap;
	curStation = start;
	numOnBoard = 0;		

	srand ((unsigned)time(NULL));
}

int CommuterTrain::getMaxCapacity()
{
	return maxCapacity;
}

int CommuterTrain::getNumOnBoard()
{
	return numOnBoard;
}

int CommuterTrain::getCurStation()
{
	return curStation;
}

int CommuterTrain::getTotalStations()
{
	return totalStations;
}

int CommuterTrain::getDestination()
{
	return destination;
}

void CommuterTrain::loadPax()
{
	int peopleWaiting;
	int maxWaiting = 350;
	peopleWaiting = CommuterTrain::genRandNumber(350);
	cout<<"There are "<<peopleWaiting<<" people waiting to get on the train at Station "<<curStation<<"."<<endl;
	if(peopleWaiting > (maxCapacity-numOnBoard))
	{
		cout<<"Sorry, not everyone can get on the train!"<<endl;
		numOnBoard = maxCapacity;
		cout<<"Loading finished, full passenger capacity of "<<maxCapacity<<" on board!"<<endl;
	}
	else
	{
		numOnBoard+=peopleWaiting;
		cout<<"Loading finished, passenger capacity of "<<numOnBoard<<" on board!"<<endl;
	}
}

void CommuterTrain::unloadPax()
{
	int peopleWantingOff;
	peopleWantingOff = CommuterTrain::genRandNumber(numOnBoard);
	numOnBoard -= peopleWantingOff;
	cout<<peopleWantingOff<<" have gotten off the train!"<<endl;
}

void CommuterTrain::SetDestination(int dest)
{
	destination=dest;
}

void CommuterTrain::moveTrain(int nextStation)
{
	destination = nextStation;
	cout << "Leaving station " << curStation << " for station "
		<< nextStation << " with "
		<< numOnBoard  << " passengers."<<endl;
	cout<<"Arriving at station "<<nextStation<<"!"<<endl;
	curStation = destination;
}

void CommuterTrain::setCurrentStation(int setcurstat)
{
	curStation = setcurstat;
}

int CommuterTrain::genRandNumber(int maxNum)
{
	return (rand() % (maxNum + 1));
}