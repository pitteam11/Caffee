#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;

int test4_by_do(int start, int end) {
	if (end < start)
		return 0;
	int summ = 0;
	do {
		summ += start++;
	} while (start <= end);
	return summ;
}

int sum = 0;
int recursion(int n) {
	if (n == 32) { 
		return sum;
	}
	sum += n;
	return recursion(n+1);
}

int recursion2(int n, int sum2 = 0) {
	if (n == 32) {
		return sum2;
	}
	sum2 += n;
	return recursion2(n+1, sum2);
}

int recursion3(int n) {
	static int s = 0;
	if (n <= 33) {
		return s;
	}
	s += n;
	return recursion3(++n);
}

void quicSort(int sz, int arr[]) {
	int p = arr[sz / 2];
	int i = 0, j = sz - 1;
	do {
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quicSort(j + 1, arr);
	if (i < sz) quicSort(sz-i, arr+i);
}

void my_swap(int *pa, int* pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
	//cout << "a = " << a << ", b = " << b << endl;
}

void my_swap2(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
	//cout << "a = " << a << ", b = " << b << endl;
}

void my_swap3(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
	//cout << "a = " << a << ", b = " << b << endl;
}

struct Rectangle {
	double w;
	double h;
	double x;
	double y;

	void init(int x1, int y1, int w1, int h1) {
		x = x1;
		y = y1;
		w = w1;
		h = h1;
	}

	double area() {
		return w * h;
	}
};


void main() {	
	//cout << recursion(17);

	int arr[10]{1,5,3,4,2,6,7,8,9,0};
	cout << arr << " " << arr[0] << endl;
		
	int *pArr0 = arr;

	int val = 14;
	int* pAdr = &val;

	//arr[k] == *(arr + k)

	cout << *pAdr << endl;


	for (int k = 0; k < 10; k++)
		cout << arr[k] << " ";
	cout << endl;

	quicSort(10, arr);

	for (int k = 0; k < 10; k++)
		cout << arr[k] << " ";
	cout << endl;

	cout << "Test my_swap" << endl;

	int a = 3, b = 5;
	cout << "a = " << a << ", b = " << b << endl;
	//my_swap(&a, &b);
	my_swap2(a, b);
	cout << "a = " << a << ", b = " << b << endl;

	Rectangle r1;

	r1.init(200, 100, 12, 34);

	/*r1.x = 100;
	r1.y = 200;
	r1.h = 400;
	r1.w = 800;*/

	cout << r1.area() << endl;
}