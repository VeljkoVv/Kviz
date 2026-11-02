#include "kviz.h"
#include "pitanje.h"
#include "baza.h"
#include "igra.h"
#include <iostream>
#include <string>
#include <vector> 
#include <map>

#define DB_PATH "db/kviz.db"
    
  
int main(){
    Igra i;
    Baza b(DB_PATH);
    i.zapocniIgru();
    if(!i.odaberiKviz(b)){ return 1;}

    i.igrajKviz(b);
    
    i.krajKviza();

    
    return 0;
}