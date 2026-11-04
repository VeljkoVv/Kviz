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

    b.rangListaUpis(i.getIme(), i.getBodovi(), i.getKviz().getId());
    b.rangListaKviza(i.getKviz().getId(), i.getKviz().getNaziv());

    return 0;
}