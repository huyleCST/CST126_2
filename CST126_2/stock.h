//--------------------------------------------------------------------
// stock.h
//     
//--------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

#ifndef STOCKH
#define STOCKH

//--------------------------------------------------------------------
//class Stock {
//public:
//	//Stock() { symbol = ' '; name = "";  price = 0.0; earning = 0.0; }; //•	A default constructor that sets the stock symbol and name to blanks and the price and earnings to zero.
//	//Stock(string n, string k, double p, double e) { symbol = n; name = k; price = p; earning = e; };
//	void PrintName(void) { cout << symbol; };
//private:
//	string symbol; 
//	string name;
//	double price;
//	double earning;
//};

class stock {
public:
	stock() { symbol = ' '; name = "";  price = 0.0; earning = 0.0; };
	//stock() { (string symbol, string name, double price, double earning; };//•	A default constructor that sets the stock symbol and name to blanks and the price and earnings to zero.
	void print(void) { cout << symbol; };
	double getPrice(double) const { return price; };
	double updatePrice(double new_price )  { price = new_price; };
private:
		string symbol; 
		string name;
		double price;
		double earning;
};

#endif;