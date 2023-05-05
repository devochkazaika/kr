#include <iostream>
#include "city.h"
#include <fstream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;
    output.open("../output.txt");   //файл для записи
    input.open("../input.txt");     //файл для чтения
    char d;                         //количество городов и названия их
    input >> d;             
    int n = int(d-'0');             //количество городов
    int n_d = n * (n-1)/2;          //количество ребер(дорог) для полного графа
    int number = 0;                 //число в массиве городов
    city *mas_cit = new city[n];    //массив городов
    way *mas_ways = new way[n_d];   //массив дорог
    bool z = true;                  //флаг полного ввода
    int zk = 0;                     //настоящее количество дорог
    while (!input.eof()){
        city *one = NULL;           //первый город
        city *two = NULL;           //второй город
        char d[20];
        int k;                      //стоимость дороши между ними
        input >> d;
        if (*d == '.'){             //если введена точка остановить ввод
            z = false;
            break;
        };
        if (input.eof()) break;
        one = insert_city(d, &mas_cit, n, &number); //добавление города в массив
        input >> d;
        two = insert_city(d, &mas_cit, n, &number);
        input >> k;
        mas_ways[zk].first = one;   //добавление дороги в массив дорог
        mas_ways[zk].second = two;
        mas_ways[zk].weight = k;
        zk = zk + 1;
        if (zk > n_d){              //если количество дорог больше максимального
            output << "Количество дорог больше";
            return 0;
        }
    }
    
    if (zk != n_d && z){            //если файл введен не полностью и нельзя построить граф
        output << "Введены не все дороги";
        return 0;
    }
    heapSort(mas_ways, zk);         //пирамидальная сортировка дорог
    char **mas_c = new char*[n];    //массив для названий городов уже в системе
    for (int i=0; i<n; i++){
        mas_c[i] = new char[20];
    }
    int s = 0;
    int kol_otvet = 0;
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
            kol_otvet++;
        }
    }
    delete[] mas_ways;
    output << "Total sum:" << sum;
    input.close();
    output.close();
    if (s != n){
        output.open("../output.txt");
        output << "Введено неверное количество городов";
        output.close();
        return 0;
    }
    if (kol_otvet != n-1){
        output.open("../output.txt");
        output << "Систему дорог, связывающую все города между, построить невозможно";
        output.close();
        return 0;
    }
    return 1;
}

