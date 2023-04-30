#include <iostream>
#pragma once
#include <cstring>

struct city;
using namespace std;

struct way{
    city *first;
    city *second;
    int weight;
};


struct city{
    char name[20];
};

void zap(char *a, char *b){
    for (int i=0; i<20; i++){
        a[i] = b[i];
    }
}


city *insert_city(char *d, city **mas_cit, int n, int *number){
    for (int i=0; i<n; i++){
        if (strcmp(d, (*mas_cit)[i].name) == 0){
            return &((*mas_cit)[i]);
    }}
    *number += 1;
    zap((*mas_cit)[*number-1].name, d);
    return &((*mas_cit)[*number-1]);
}


bool pr(city *mas_ways, char **mas_c, int n){
    bool t1 = true;
    bool t2 = true;
    for (int i=0; i<n; i++){
        if (strcmp((mas_ways)->name, mas_c[i])==0){
            t1 =false;
            break;
        };
    }
    return t1;
}


void rep(way *t, way *m){
    way n = *t;
    *t = *m;
    *m = n;
}

void siftDown(way *t, int root, int n){
    int max = root;
    int l = root*2 +1;
    int r = root*2 + 2;
    if (l < n){
        if (t[l].weight > t[max].weight) max = l;
    }
    if (r < n){
        if (t[r].weight > t[max].weight) max = r;
    }
    if (max != root){
        rep(t+max, t + root);
        siftDown(t, max, n);
    }
}

void heapSort(way *t, int n) 
{
  for (int i = (n / 2); i >= 0; i--)
    siftDown(t, i, n - 1);
  for (int i = n - 1; i >= 1; i--)
  {
    rep(t+i, t);
    siftDown(t, 0, i - 1);
  }
}