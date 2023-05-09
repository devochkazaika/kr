#include <iostream>
#pragma once
#include <cstring>

struct city;
using namespace std;

struct way{         //структура ребра(дороги)
    city *first;    //первый город
    city *second;   //второй город
    int weight;     //стоимость
};


struct city{        //структура города
    char name[20];  //имя
};

void zap(char *a, char *b){     //запись имени
    for (int i=0; i<20; i++){
        a[i] = b[i];
    }
}


city *insert_city(char *d, city **mas_cit, int n, int *number){ //добавление города в массив
    for (int i=0; i<n; i++){
        if (strcmp(d, (*mas_cit)[i].name) == 0){
            return &((*mas_cit)[i]);
    }}
    *number += 1;
    zap((*mas_cit)[*number-1].name, d);
    return &((*mas_cit)[*number-1]);
}


bool pr(city *mas_ways, char **mas_c, int n){  //проверка есть ли город в системе
    bool t1 = true;
    for (int i=0; i<n; i++){
        if (strcmp((mas_ways)->name, mas_c[i])==0){
            t1 =false;
            break;
        };
    }
    return t1;
}


void rep(way *t, way *m){   //swap дорог
    way n = *t;
    *t = *m;
    *m = n;
}

void siftDown(way *t, int root, int n){ //построение кучи
    int max = root; //индекс
    int l = root*2 +1;  //левый потомок
    int r = root*2 + 2; //правый потомок
    if (l < n){     //если левый меньше чем предок поменять местами
        if (t[l].weight > t[max].weight) max = l;
    }
    if (r < n){
        if (t[r].weight > t[max].weight) max = r;
    }
    if (max != root){   //если предок был заменен тогда поменять местами
        rep(t+max, t + root);
        siftDown(t, max, n); //достроить кучу для ячейки в которой оказался предок
    }
}

void heapSort(way *t, int n) 
{
  for (int i = (n / 2)-1; i >= 0; i--)
    siftDown(t, i, n - 1);  //построить кучу
  for (int i = n-1; i >= 0; i--)
  {
    rep(t+i, t);   //заменить наибольший на наименьший
    siftDown(t, 0, i); //пересобрать кучу для i
  }
}