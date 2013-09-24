// FILE	:	OrdersProcessed.h
// PROG	:	Zachery Lippe
//Purpose: a class that stores valid part orders in a notepad file
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class OrdersProcessed
{
	private:
		string file;
		void openFile(string);
		char fileOpenSuccess;
	public:
		OrdersProcessed(string);
		char getFileStatus();
		void saveRecord(int, int, double);
		void closeFile();
		void displayOrders();
		double calcTotalCostOfOrders();
};
OrdersProcessed::OrdersProcessed(string filepass)
{
	file=filepass;
	fileOpenSuccess='F';
	OrdersProcessed::openFile(file);
};
void OrdersProcessed::openFile(string fileToOpen)
{
	ofstream ordersOut(file, ios::out);
	if (ordersOut.is_open())
	{
		fileOpenSuccess='T';
	}
	else	
	{
		fileOpenSuccess='F';
	}
}
char OrdersProcessed::getFileStatus()
{
	return fileOpenSuccess;
}
void OrdersProcessed::saveRecord(int searchNum, int quantity, double total)
{
	ofstream ordersOut(file, ios::app);
	if (fileOpenSuccess=='T')
			{
				ordersOut<<searchNum<<'\t'<<quantity<<'\t'<<total<<endl;
			}
}
void OrdersProcessed::closeFile()
{
	ofstream close();
}
void OrdersProcessed::displayOrders()
{
	ifstream ordersIn(file, ios::in);
	int ct=1;
	int partNum=0;
	double tot=0;
	int quant=0;


	if (ordersIn.is_open())
	{
		ordersIn>>partNum>>quant>>tot;

		cout<<"   #   PART ID#   QTY ORDERED    TOTAL"<<endl; 
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<setw(4)<<ct<<setw(8)<<partNum<<setw(14)<<quant<<setprecision(2)<<setw(9)<<tot<<endl;

		while (!ordersIn.eof())
		{
			++ct;
			ordersIn>>partNum>>quant>>tot;
			if(ordersIn.eof())
				break;  
			cout<<setw(4)<<ct<<setw(8)<<partNum<<setw(14)<<quant<<setprecision(2)<<setw(9)<<tot<<endl;
		}

		ordersIn.close();
	}

	else	
	{
		cout << "File failed to open.";
	}
}
double OrdersProcessed::calcTotalCostOfOrders()
{
	ifstream ordersIn(file, ios::in);
	double totalTotal=0;
	int partNum=0;
	double tot=0;
	int quant=0;

	if (ordersIn.is_open())
	{
		ordersIn>>partNum>>quant>>tot;
		totalTotal+=tot;	

		while (!ordersIn.eof())
		{
			ordersIn>>partNum>>quant>>tot;
			if(ordersIn.eof())
				break;  
			totalTotal+=tot;
		}

		ordersIn.close();
	}

	else	
	{
		cout << "File failed to open.";
	}
	return totalTotal;
}