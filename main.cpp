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
    city *kol = new city[n];
    dorog *p = new dorog[n * (n-1)/2];
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
        cout << "=" << one << endl;
        (p[n_d]).first = one;
        (p[n_d]).second = two;
        (p[n_d]).weight = k;
        n_d += 1;

    }
    cout << p[1].first;
}