#include <iostream>
#include "city.h"
#include <fstream>

using namespace std;

int main(){
    ifstream input;
    ofstream output;
    output.open("../output.txt");
    input.open("../input.txt");
    char d;
    input >> d;
    int n = int(d-'0');
    int n_d = n * (n-1)/2;
    int number = 0;
    city *kol = new city[n+10];
    dorog *dq = new dorog[n_d];
    int zk = 0;
    while (!input.eof()){
        city *one = NULL;
        city *two = NULL;
        char *d = new char[20];
        int k;
        input >> d;
        //cout << d << endl;
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
    dorog *otvet = new dorog[zk];
    sort_d(dq, zk);
    char **mas_c = new char*[n];
    for (int i=0; i<n; i++){
        mas_c[i] = new char[20];
    }
    int s = 0;
    int sum = 0;
    output << "Ways:" << endl;
    for (int i=0; i<zk; i++){
        bool t1 = true;
        bool t2 = true;
        t1 = pr(dq[i].first, mas_c, s);
        t2 = pr(dq[i].second, mas_c, s);
        if (t1 || t2){
            if (t1){
                zap(mas_c[s], dq[i].first->name);
                s = s + 1;
            }
            if (t2){
                zap(mas_c[s], dq[i].second->name);
                s = s + 1;
            }

            output <<dq[i].first->name << "->" <<dq[i].second->name<<" W:" << dq[i].weight << endl;
            sum = sum + dq[i].weight;
        }
    }
    delete[] otvet;
    delete[] kol;
    delete[] dq;
    output << "Total sum:" << sum;
    input.close();
    output.close();
    return 1;
}

