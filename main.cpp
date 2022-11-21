#include <iostream>
#include <Windows.h>
#include "Dish.h"
#include <conio.h>

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

    kk.fromString("Картофель Б:2.2 Ж1.4 У:16.3 KK:77.5");
    cout << dish1.toString() << endl;
    cout << kk.toString();
}