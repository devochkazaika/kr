#include <iostream>
#include "city.h"
#include <fstream>

using namespace std;

int main(){
    ifstream input;
    input.open("file.txt");
    int n;
    char d;
    input >> d;
    n = int(d-'0');
    int number = 0;
    int n_d = 0;
    city *kol = new city[n+2];
    for (int i=0; i<n; i++){
        kol[i].mas = new city[n-1];
        kol[i].h = new int[n-1];
    }
    cout << d-'0';
    while (!input.eof()){
        city *one = NULL;
        city *two = NULL;
        char d;
        int k;
        input >> d;
        if (input.eof()) break;
        one = prov(d, &kol, n, &number);
        input >> d;
        two = prov(d, &kol, n, &number);
        input >> k;
        //cout << one->mas << endl;
        one[one->n].mas = two;
        one->h[one->n] = k;
        two[one->n].mas = one;
        two->h[two->n] = k;
        one->n += 1;
        two->n += 1;
    }
    city *tmp = kol;
    tmp->weight = 0;

    for (int i=0; i<n; i++){
        city *tmp = (kol + i);
        
    }
}


city *min(city *mas, int n){
    city *k = mas;
    for (int i=1; i<n; i++){
        if (k->weight > mas[i].weight){
            k = &mas[i];
        }
    }
    return k;
}