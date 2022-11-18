#pragma once
#include <iostream>
#include <string>

using namespace std;

// Белки Жиры Углеводы Ккал
struct PFCKk {
	int Proteins;
	int Fat;
	int Carbohydrates;
	int Energy_Kk;
};

struct Product {
	string name;
	PFCKk pfckk;
	int weight_g;
};

struct Dish {
	string type; // first, drink, ...
	string name;
	int weight_g; // 
	int price_r;
	Product* contents;

};

