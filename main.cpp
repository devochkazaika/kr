#include <iostream>
#include "city.h"
#include <fstream>

using namespace std;

int main(){
    ifstream input;
    input.open("file.txt");
    char d;
    input >> d;
    int n = int(d-'0');
    int number = 0;
    city *kol = new city[n+2];
    dorog *dq = new dorog[n * (n-1)/2];
    int zk = 0;
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
        dq[zk].first = one;
        dq[zk].second = two;
        dq[zk].weight = k;
        zk = zk + 1;
    }
    dorog *otvet = new dorog[n];
    sort_d(dq, 6);
    char *mas_c = new char[n];
    int s = 0;
    int sum = 0;
    cout << "Ways:" << endl;
    for (int i=0; i<(n-1)*n/2; i++){
        bool t1 = true;
        bool t2 = true;
        t1 = pr(dq[i].first, mas_c, s);
        t2 = pr(dq[i].second, mas_c, s);
        if (t1 || t2){
            if (t1){
                mas_c[s] = dq[i].first->name;
                s = s + 1;
            }
            if (t2){
                mas_c[s] = dq[i].second->name;
                s = s + 1;
            }

            cout <<dq[i].first->name << "->" <<dq[i].second->name<<" W:" << dq[i].weight << endl;
            sum = sum + dq[i].weight;
        }
    }
    cout << "Total sum:" << sum;
}

