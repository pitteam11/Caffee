#include <iostream>
#include <Windows.h>
#include "Dish.h"
#include <conio.h>
#include "data.h"
#include <fstream>


using namespace std;

#define DEBUG_LOG(message) if(1) cout << (message) << endl

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    DEBUG_LOG("DEBUG MODE");

    cout << stof("2,2") << endl;

    //_getch();
    Dish dish1;
    
    dish1.name = "Цезарь";
    dish1.type = "салат";
    dish1.price_r = 220;
    dish1.weight_g = 250;
    
    PFCKk kk; 
    kk.Carbohydrates = 100;
    kk.Fat = 100;
    kk.Proteins = 100;
    kk.Energy_Kk = 100;
    /*
    for (int k = 0; k < sizeof(product_data) / sizeof(product_data[0]); k++) {
        kk.fromString(product_data[k]);
        cout << kk.toString() << endl;
    }
    */
    ifstream fin("bd/фрукты.csv");
    string outstr;
    if (fin.is_open()) {
        outstr = "";
        getline(fin, outstr);
        while (!fin.eof()) {
            outstr = "";
            getline(fin, outstr);
            kk.fromString(outstr);
            cout << kk.toString() << endl;
        }       
    }
    else {
        cout << "can not open the file" << endl;
    }
    fin.close();

}
