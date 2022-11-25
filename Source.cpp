#include <iostream>
#include "Header.h"

using namespace std;



void show(MyStruct mys1) {
	mys1.x = mys1.y;
	cout << mys1.x << " " << mys1.y << endl;
}

void init(MyStruct * pmys1) {
	//  (*pmys1).x = pmys1->x;
	pmys1->x = 0;
	pmys1->y = 0;
}

void init1(MyStruct& mys1) {	
	mys1.x = 0;
	mys1.y = 0;
}

// не даЄт выйгрыша в пам€ти дл€ хранени€ экземпл€ров структуры.
struct S2 {
	int x:4;
	long long m:4;
};

struct ST1 {
	int x;
	ST2 *st2;
};

struct ST2 {
	int y = 0;
	ST1 *st1;
	MyStruct mys1;
};

void main() {
	struct nStruct {
		double dd;
		double ff;
	};

	struct {
		double x;
		double y;
	} point1, point2, point3;

	point1.x = 12;
	point2.y = 13;

	MyStruct my1;
	MyStruct my2[10];

	my1.x = 12;
	my1.y = 14;

	show(my1);


	//init(&my1);
	init1(my1);
	cout << my1.x << " " << my1.y << endl;


	my2[2].x = 15;
	my2[2].y = 17;


	S1 car;
	cout << sizeof(car) << endl;

	S2 car2;
	car2.x = 258;
	car2.m = 12;

	cout << car2.x << " " << car2.m << endl;

	cout << sizeof(car2) << endl;

	cout << "HHHH" << endl;

	const int n = 5;
	int arr13[n];

	S1withMetod name1;
	name1.show();
	unsigned float ff = 1.0;

	int arr1[]{ 1, 2, 3 };
	int arr2[]{ 2, 1, 3 };
}