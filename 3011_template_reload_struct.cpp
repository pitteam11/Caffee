#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fun1(int arr[], int& val, int& id) {
	for (int k = 0; k < 10; k++) {
		if (arr[k] == 106) {
			val = arr[k];
			id = k;
			return;
		}
	}
}

struct Res {
	int id;
	int val;
};

Res fun1(int arr[]) {
	Res res;
 	for (int k = 0; k < 10; k++) {
		if (arr[k] == 106) {
			res.val = arr[k];
			res.id = k;
			return res;
		}
	}
}

int task5(int a, int b) {
	return a + b;
}

double task5(double a, double b) {
	return a * b;
}

int task5(string a, string b) {
	return a.size() + b.size();
}

int* fan(int arr[]) {
	int res[2]; 
	for (int k = 0; k < 10; k++) {
		if (arr[k] == 106) {
			res[0] = arr[k];
			res[1] = k;
			return res;
		}
	}
}

template<typename T>
void show_arg(T x) {
	cout << "Argument is " << x << endl;
}

void task8(int val) {
	int* arr;
	int num_delitel = 0;
	for (int k = 1; k < val; k++) {
		if ((val % k) == 0)
			num_delitel++;
	}
	arr = new int[num_delitel];
	int curr_del = 0;
	for (int k = 1; k < val; k++) {
		if ((val % k) == 0)
			arr[curr_del++] = k;
	}

	for (int k = 0; k < curr_del; k++) {
		cout << arr[k] << " ";
	}
	cout << "\n";
	delete[] arr;
}

int badfactor(int n) {
	if (n == 1)
		return 1;
	return n + badfactor(n - 1);
}

void wasd(char key) {
	switch (key)	{
	case 'w': cout << "up"; 
	case 's': cout << "down"; 
	case 'a': cout << "left"; 
	case 'd': cout << "right"; 
	default: cout << " default";  
	}
}

struct Varior {
	string name = "John";
	int atac;
	double speed; 
	string laugh;
};

void main() {
	Varior man1{ "John", 130, 1.01, "HAHAHAHA" };
	man1.speed = 1.34;
	cout << man1.name << " " << man1.laugh << endl;

	ofstream fout("text.txt");
	fout << man1.name << " a: "
		<< man1.atac << " s: "
		<< man1.speed << " L: "
		<< man1.laugh << endl;
	fout.close();

	ifstream fin("text.txt");
	string str;
	if (fin.is_open()) {
		getline(fin, str);
		cout << str;
		fin.close();
	}


	char key;
	cin >> key;
	wasd(key);
	cout << endl;

	int arr[10];
	int k = 0;
	do {
		arr[k] = 101 + k;
		k++;
 	} while (k < 10);

	int id, val;
	fun1(arr, val, id); // id = 5, val = 106; 
	cout << val << " " << id << endl;

	Res res = fun1(arr);
	id = res.id;
	val = res.val;
	cout << val << " " << id << endl;

	int *res2;
	res2 = fan(arr);
	id = res2[0];
	val = res2[1];
	cout << val << " " << id << endl;



	task8(754);


	int arr2[10];
	for (int k = 0; k < 10; k += 2) {
		arr2[k] = arr[k+1];
	    arr2[k+1] = arr[k];
	}
	
	for (int k = 0; k < 10; k++)
		cout << arr2[k] << " ";
	cout << endl;

	char arr3[3][3]{ {'X', 'O', 'O'}, 
		             {'O', 'X', 'X'},
		             {'O', 'X', 'O'}};

	for (int k = 0; k < 3; ++k) {
		
		for (int n = 0; n < 3; ++n) {
			if (n == 0)
				cout << " ";
			cout << arr3[k][n];
			if (n < 2) {
				cout << " |";
			}
			cout << " ";
		}		
		cout << endl;
		if(k < 2)
			cout << "-----------" << endl;
	}
	cout << endl;	
}

