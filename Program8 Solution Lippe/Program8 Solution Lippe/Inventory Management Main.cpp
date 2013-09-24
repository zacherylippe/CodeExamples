/*
FILE: INVENTORY MANAGEMENT MAIN
PROGRAMMER: ZACHERY LIPPE
PURPOSE: TO MANAGE INVENTORY ORDERS AND EXPORT A ORDER LIST FILE
*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Inventory Management Class.h"
#include "OrdersProcessed.h"

int main()
{
	int searchNum=0;
	int indexNum=0;
	int quantity=0;
	double total=0;
	char success='F';

	InventoryData myInventory;
	OrdersProcessed OrdersProcessed("OrdersProcessed.dat");
	myInventory.loadArrays();
	myInventory.bubbleSort();
	success=OrdersProcessed.getFileStatus();
		if(success=='F')
			cout<<"File failed to open."<<endl;
	cout<<"Welcome to Dave's Fly By Night Completely Trustworthy Autoparts Store!\n\n";
	cout<<"To exit, enter -1 into part ID number then press return."<<endl;
	cout<<"Please input the part's ID number, then you will be asked"<<endl;
	cout<<"for the quantity desired."<<endl;
	cout<<"Part ID number: ";
	cin>>searchNum;
	
	while(searchNum!=-1)
	{
		cout<<endl<<"What quantity is desired of this part? ";
		cin>>quantity;
		cout<<endl;
		cout<<"Searching..."<<endl;
		indexNum=myInventory.binSearch(searchNum);
		if(indexNum==-1)
		{
			cout<<"Error: bad command or file name."<<endl;
		}
		else
		{
			cout<<"Part found."<<endl;
			total=myInventory.getPrice(indexNum)*quantity;
			cout<<fixed;
			cout<<"PART ID#   PRICE   QTY ORDERED    TOTAL"<<endl;
			cout<<setw(8)<<searchNum<<setw(8)<<setprecision(2)<<myInventory.getPrice(indexNum);
			cout<<setw(14)<<quantity<<setprecision(2)<<setw(9)<<total<<endl;
			OrdersProcessed.saveRecord(searchNum, quantity, total);

		}		
		cout<<"To exit, enter -1 into part ID then press return."<<endl;
		cout<<"Part ID number: ";
		cin.ignore();
		cin>>searchNum;
	}
	OrdersProcessed.closeFile();	
	system ("CLS");
	OrdersProcessed.displayOrders();
	cout<<endl<<endl<<"Total price of all orders: $"<<fixed<<setprecision(2)<<OrdersProcessed.calcTotalCostOfOrders()<<endl;
	return 0;
}
