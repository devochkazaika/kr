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


void sort_d(way *t, int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            way k = t[j];
            if (t[j].weight > t[j+1].weight){
                t[j] = t[j+1];
                t[j+1] = k;
            }
        }
    }}

void swap(way *t, way *m){
    way *n = t;
    t = m;
    m = n;
}

void siftDown(way *t, int root, int n){
    int done = 0;
    int max;
    while ((root * 2 <= n) && (!done)){
        if (root * 2 == n){
            max = root * 2;
        }
        else if(t[root*2].weight > t[root * 2+1].weight){
            max = root * 2;
        }
        else max = root * 2 + 1;
        if (t[root].weight < t[max].weight){
            swap(t[root], t[max]);
            root = max;
        }
        else{
            done = 1;
        }
    }
}

void heapSort(way *t, int n) 
{
  for (int i = (n / 2); i >= 0; i--)
    siftDown(t, i, n - 1);
  for (int i = n - 1; i >= 1; i--)
  {
    swap(t[i], t[0]);
    siftDown(t, 0, i - 1);
  }
}