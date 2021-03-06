// CST126_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace std;


#include "stock.h"

//--------------------------------------------------------------------

string symbolArray[4];
string nameArray[4];
double priceArray[4];
double earningsArray[4];
double peArray[4];
double pe = 0;

bool OpenFile(ifstream& input_file);
void print(ifstream & stock_file, string & symbol, string & name, double & price, double & earnings);
void read(ifstream & stock_file, string & symbol, string & name, double & price, double & earnings);

int main(void)
{
	//  STUDENT TASK - define your variables
	string symbol = " ";
	string name = " ";
	double price = 0;
	double earnings = 0;
	// STUDENT TASK - look these up and add a comment to each one to describe what they are doing
	cout.setf(ios::fixed);   //display decimal point and trailling zeros.
	cout.setf(ios::showpoint); //similarly, showpoint is used to display decimal point and trailing zeros of floating point numbers despiting the decimal places are not needed.
	cout.precision(2);  //set total number of degits of floating point number to be displayed.

	ifstream stock_file;
	cout << "Welcome to the Stock Picker" << endl << endl;

	if (OpenFile(stock_file)) {
		// STUDENT TASK - Loop through your stocks and print them
		read(stock_file, symbol, name, price, earnings);
		cout << endl;
		cout << "If you had a 10% appreciation in price the values would be" << endl;
		// STUDENT TASK - Loop through your stocks and 1 - give them a 10% price increase 2 - print them
		print(stock_file, symbol, name, price, earnings);
	}

	return 0;

}
void read(ifstream & stock_file, string & symbol, string & name, double & price, double & earnings)
{
	int i = 0;

	while (i < 4)
	{
		string symbol = " ";
		string name = " ";
		double price = 0;
		double earnings = 0;
		stock_file >> symbol >> name >> price >> earnings;

		pe = price / earnings;
		cout.setf(ios::left);
		cout << setw(5) << symbol << " ";
		cout << setw(25) << name;
		cout << setw(6) << "Price: " << setw(15) << price;
		cout << setw(8) << "Earnings " << setw(10) << earnings;
		cout << setw(4) << "P/E " << pe;
		cout << endl;

		symbolArray[i] = symbol;
		nameArray[i] = name;
		priceArray[i] = price;
		earningsArray[i] = earnings;
		peArray[i] = pe;

		i++;
	}
}

void print(ifstream & stock_file, string & symbol, string & name, double & price, double & earnings)
{
	int i = 0;
	double percent = 1.1;
	while (i < 4)
	{
		cout.setf(ios::left);
		cout << setw(5) << symbolArray[i] << " ";
		cout << setw(25) << nameArray[i];
		cout << setw(6) << "Price: " << setw(15) << priceArray[i] * percent;
		cout << setw(8) << "Earnings " << setw(10) << earningsArray[i];
		cout << setw(4) << "P/E " << peArray[i] * percent;
		cout << endl;

		i++;
	}
}
//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    OpenFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
bool OpenFile(ifstream& input_file)
{
	char filename[50];

	cout << "Please enter the input file name including extension (.txt) : ";
	cin >> filename;


	input_file.open(filename);

	if (input_file.fail())
	{
		cout << "ERROR: Unable to open file : " << filename << endl;
		cout << endl;
		return false;
	}
	else
	{
		cout << endl;
		return true;
	}

}
