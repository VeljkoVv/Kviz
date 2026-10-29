#include "kviz.h"
#include "pitanje.h"
#include "baza.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

    cout << "Unesite vase ime: " << endl;
    std::string ime;
    cin >> ime;

    cout << "\nTrenutno dostpni kvizovi:" << endl;
    Baza b("db/kviz.db");
    

    return 0;
}