#include <iostream>

struct city;
//struct dorog;
using namespace std;

struct dorog{
    city *first;
    city *second;
    int weight;
};


struct city{
    char name;
    int weight = 9999;
    dorog *mas;
};


city *prov(char d, city **kol, int n, int *number){
    bool t =false;
    for (int i=0; i<n; i++){
        if (d == (*kol)[i].name){
            t = true;
            break;
            }
        }
    if (!t){
        *number += 1;
        (*kol)[*number-1].name = d;
        return kol[*number-1];
    }
    return kol[*number-1];
}



