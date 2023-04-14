#include <iostream>
#pragma once
#include <cstring>

struct city;
using namespace std;

struct dorog{
    city *first;
    city *second;
    int weight;
};


struct city{
    char *name = new char[20];
};

/*bool p_s(char *a, char *b){
    for (int i=0; i<20; i++){
        if (a[i] != b[i]){
            return false;
        };
    }
    return true;
}*/

void zap(char *a, char *b){
    for (int i=0; i<20; i++){
        a[i] = b[i];
    }
}


city *prov(char *d, city **kol, int n, int *number){
    for (int i=0; i<n; i++){
        if (strcmp(d, (*kol)[i].name) == 0){
            return &((*kol)[i]);
    }}
    *number += 1;
    zap((*kol)[*number-1].name, d);
    return &((*kol)[*number-1]);
}


bool pr(city *dq, char **mas_c, int n){
    bool t1 = true;
    bool t2 = true;
    for (int i=0; i<n; i++){
        if (strcmp((dq)->name, mas_c[i])){
            t1 =false;
            break;
        };
    }
    return t1;
}


void sort_d(dorog *t, int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            dorog k = t[j];
            if (t[j].weight > t[j+1].weight){
                t[j] = t[j+1];
                t[j+1] = k;
            }
        }
    }}