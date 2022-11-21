#include <iostream>

using namespace std;

int counter = 0;

int factorial(int n) {
	counter++;
	if (n < 2)
		return 1;
	return n * factorial(n - 1);
}


int fibonaci(int n) {	
	if (n < 2)
		return 1;
	return fibonaci(n - 1) + fibonaci(n - 2);
}

void show_nums(int k = 0) {
	cout << k << " ";
	if (k < 5)
		show_nums(k + 1);
}

void show_by_circle() {
	int k = 0;
	while (k <= 5) {
		cout << k++ << " ";
	}
}

void main() {
	show_nums();
	cout << endl;
	show_by_circle();
	cout << endl;
	cout << "factorial: " << factorial(15) << " " << counter << endl;
	cout << fibonaci(4) << endl;
}

