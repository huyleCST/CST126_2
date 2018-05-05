//--------------------------------------------------------------------
// stock.cpp
//--------------------------------------------------------------------

#include "stdafx.h"
#include <iostream>
#include <iomanip>

#include "stock.h"
void Print(string symbol, string name, double price, double earning) 
{
	double pe = price / earning;
	cout.setf(ios::left);
	cout << setw(5) << symbol << " ";
	cout << setw(25) << name;
	cout << setw(6) << "Price: " << setw(15) << price;
	cout << setw(8) << "Earnings " << setw(10) << earning;
	cout << setw(4) << "P/E " << pe;
	cout << endl;
}