// FILE	:	Inventory Management Class.h
// PROG	:	Zachery Lippe
//Purpose: a class that helps track inventory parts.
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


class InventoryData
{
	private:
		int IDArray[200];
		double PriceArray[200];
		double summaryArray[200][2]; //yeah... please don't make more than 200 queries. Your computer might explode or something, I have no idea.
		int loadCount;
		int foundSeq;
		int foundBin;
		int query;
		int summaryArrayIndex;

	public:
		InventoryData();
		void loadArrays();
		int seqSearch(int);
		int binSearch(int);
		void displayIDArray();
		void displayPriceArray();
		double getPrice(int);
		void bubbleSort();
		void summary();
};
InventoryData::InventoryData()
{
	loadCount=0;
	query=0;
	for (int ct = 0; ct < 200; ++ct) 
	{
		IDArray[ct] = 0;
		PriceArray[ct]=0;
		summaryArray[ct][0]=0;
		summaryArray[ct][1]=0;
		summaryArrayIndex=0;
	}
}

void InventoryData::loadArrays()
{
	ifstream  numfile;
	numfile.open ("masterInventory.dat");
	if (numfile.is_open())
	{
		numfile	>> IDArray[loadCount];
		numfile >> PriceArray[loadCount];

		while (!numfile.eof())
		{
			++loadCount;
			numfile	>> IDArray[loadCount];
			numfile >> PriceArray[loadCount];
		}

		numfile.close();
	}

	else	
	{
		loadCount = -1;
		cout << "File failed to open.";
	}
}


int InventoryData::seqSearch(int target)
{
	int ct=0;
	int ind=0;
	int found=-1;
	while(ind<loadCount)
	{
		 if(target==IDArray[ind])
		 {
			 found=ind;
			 ind=loadCount;
		 }
		 else
		 {
			 ++ind;
			 ++ct;
		 }		
	}
	
	//out<<"Comparisons required for answer: "<<ct+1<<endl;
	return found;
}

int InventoryData::binSearch(int target)
{
	//ptCount=loadCount
	//mid=found
	int first=0;
	int last=loadCount-1;
	int found=0;
	int mid=0;
	int ct=0;
	while(first<=last&&found==0)
	{
		
		mid=(first+last)/2;
		if(IDArray[mid]==target)
			found=1;
		else
		{
			if(IDArray[mid]<target)
			{
				++ct;
				first=mid+1;
			}
			else
				last=mid-1;
		}
	}
	if(found==0)
	{
		mid=-1; 
	}
	//cout<<endl<<"Comparisons required for answer: "<<ct+1<<endl;
	return mid;
}

void InventoryData::displayIDArray()
{
	cout<<"ID Array is as follows:"<<endl;
	for(int ct=0; ct < loadCount; ct++)
		cout<<IDArray[ct]<<endl;
}

void InventoryData::displayPriceArray()
{
	cout<<"Price Array is as follows:"<<endl;
	for(int ct=0; ct < loadCount; ct++)
		cout<<PriceArray[ct]<<endl;
}

double InventoryData::getPrice(int index)
{
	return PriceArray[index];
}

void InventoryData::bubbleSort()
{
	int last = loadCount -1;
	
	while(last>0)
	{	
		int ind=0;
		int swap=0;
		while(ind<last)
		{
			if(IDArray[ind]>IDArray[ind+1])
			{
				int intTempStorage=0;
				double doubleTempStorage=0;
				intTempStorage=IDArray[ind];
				IDArray[ind]=IDArray[ind+1];
				IDArray[ind+1]=intTempStorage;
				doubleTempStorage=PriceArray[ind];
				PriceArray[ind]=PriceArray[ind+1];
				PriceArray[ind+1]=doubleTempStorage;
				swap=1;
			}
			ind++;
		}
		if(swap==0)
			last=0;
		else
			last=last-1;
	}
}

void InventoryData::summary()
{
	int ct=0;
	cout<<"Your search history is as follows:"<<endl;
	cout<<"   # Part Number     Price"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	while(ct<query)
	{
		cout<<setfill(' ');
		cout<<setw(4)<<ct+1;
		cout<<setw(12)<<summaryArray[ct][0];
		cout<<setw(5)<<"$"<<setprecision(2)<<fixed<<summaryArray[ct][1]<<endl;
		ct++;
	}
	cout<<endl<<"End of record"<<endl;
}