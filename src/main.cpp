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
    b.ucitajSveKvizove();
    b.ucitajSvaPitanjaKviza(1);


    return 0;
}