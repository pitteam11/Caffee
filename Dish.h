#pragma once
#include <iostream>
#include <string>

using namespace std;

struct PFCKk {
	string name = "any";
	double Proteins = 0;
	double Fat = 0;
	double Carbohydrates = 0;
	double Energy_Kk = 0;

	string toString();

	bool getValue(string str, string ctrl, double& res);

	double getValue(string str, string ctrl);

	void fromString(string str);	
};



struct Product {
	string name;
	PFCKk pfckk;
	int weight_g;

	string toString() {
		return name;
	}
};

struct Dish {
	string type; // first, drink, ...
	string name;
	int weight_g; // 
	int price_r;
	Product* contents;

	string toString() {
		return type + " " + name;
	}
};
