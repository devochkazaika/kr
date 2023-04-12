#include <iostream>
#pragma once

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
    city *mas;
    int *h;
    int n = 0;
};


city *prov(char d, city **kol, int n, int *number){
    for (int i=0; i<n; i++){
        if (d == (*kol)[i].name){
            return &((*kol)[i]);
    }}
    *number += 1;
    (*kol)[*number-1].name = d;
    return &((*kol)[*number-1]);
}



