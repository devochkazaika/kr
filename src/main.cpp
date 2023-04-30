#include <iostream>
#include "city.h"
#include <fstream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;
    output.open("../output.txt");
    input.open("../input.txt");
    char d;
    input >> d;
    int n = int(d-'0');
    int n_d = n * (n-1)/2;
    int number = 0;
    city *mas_cit = new city[n];
    way *mas_ways = new way[n_d];
    bool z = true;
    int zk = 0;
    while (!input.eof()){
        city *one = NULL;
        city *two = NULL;
        char d[20];
        int k;
        input >> d;
        if (*d == '.'){
            z = false;
            break;
        };
        if (input.eof()) break;
        one = insert_city(d, &mas_cit, n, &number);
        input >> d;
        two = insert_city(d, &mas_cit, n, &number);
        input >> k;
        mas_ways[zk].first = one;
        mas_ways[zk].second = two;
        mas_ways[zk].weight = k;
        zk = zk + 1;
    }
    if (zk != n_d && z){
        output << "Введены не все дороги";
        return 0;
    }
    way *otvet = new way[zk];
    heapSort(mas_ways, zk);
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
        t1 = pr(mas_ways[i].first, mas_c, s);
        t2 = pr(mas_ways[i].second, mas_c, s);
        if (t1 || t2){
            if (t1){
                zap(mas_c[s], mas_ways[i].first->name);
                s = s + 1;
            }
            if (t2){
                zap(mas_c[s], mas_ways[i].second->name);
                s = s + 1;
            }

            output <<mas_ways[i].first->name << "<->" <<mas_ways[i].second->name<<" W:" << mas_ways[i].weight << endl;
            sum = sum + mas_ways[i].weight;
        }
    }
    delete[] otvet;
    delete[] mas_cit;
    delete[] mas_ways;
    output << "Total sum:" << sum;
    input.close();
    output.close();
    return 1;
}

