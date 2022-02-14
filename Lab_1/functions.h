#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void input(string in, vector<char> &vec) //функция для заполнения векторов (множеств)
{
    cout << "input new arr: \n";
    cin >> in;                  //вводим вспомогательную строку
    sort(in.begin(), in.end()); //сортируем ее
    for (int i = 0; i < in.size(); i++)
    {
        vec.push_back(in[i]); //заполняет вектор char'ов посимвольно из отсортированной строки
    }
    in.clear();
    cout << '\n';
}

void printVec(vector<char> vec) //функция для вывода содержимого множества
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << '\n';
}