#include <iostream>
#include <Windows.h>
#include "Dish.h"

using namespace std;

#define DEBUG_LOG(message) if(1) cout << (message) << endl

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    DEBUG_LOG("DEBUG MODE");

    Dish dish1;

}