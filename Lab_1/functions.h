#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> //для ф-ии sort
#include <algorithm>
using namespace std;

void input(vector<char> &vec) //функция для заполнения векторов (множеств)
{
    string in;
    cout << "input new arr: \n";
    cin >> in; //вводим вспомогательную строку
    for (int iter = 0; iter < in.size(); iter++)
    {
        vec.push_back(in[iter]); //заполняет вектор char'ов посимвольно из отсортированной строки
    }
    sort(vec.begin(), vec.end()); //сортируем содержимое вектора
    in.clear();
    cout << '\n';
}

void printVec(vector<char> vec) //функция для вывода содержимого множества
{
    for (int iter = 0; iter < vec.size(); iter++)
    {
        cout << vec[iter];
    }
    cout << "\n";
}

int getSize(vector<char> &vec1, vector<char> &vec2)
{
    int size = 0;
    if (vec1.size() > vec2.size())
    {
        size = vec1.size();
        vec2.resize(vec1.size()); // resize вектора для устранения ошибки выхода за границы массива в дальнейшем
    }
    else if (vec1.size() < vec2.size() or vec1.size() == vec2.size())
    {
        size = vec2.size();
        vec1.resize(vec2.size()); // resize вектора для устранения ошибки выхода за границы массива в дальнейшем
    };
    return size;
}
bool crossing(vector<char> vec1, vector<char> vec2, vector<char> &output) // works properly
{
    int size = getSize(vec1, vec2);
    bool flag = false;
    for (int iter = 0; iter < size; iter++)
    {
        for (int subIter = 0; subIter < size; subIter++)
        {
            if (vec1[iter] == vec2[subIter])
            {
                output.push_back(vec1[iter]);
                flag = true;
            }
        }
    }
    return flag;
}

bool isNotExist(vector<char> output, char symbol) //вспомогательная функция для проверки наличия в множестве
{
    for (int iter = 0; iter < output.size(); iter++)
    {
        if (output[iter] == symbol)
        {
            return false;
        }
    }
    return true;
}

void unification(vector<char> vec1, vector<char> vec2, vector<char> &output)
{
    output.insert(output.end(), vec1.begin(), vec1.end());
    output.insert(output.end(), vec2.begin(), vec2.end());
    sort(output.begin(), output.end());
    auto ip = unique(output.begin(), output.begin() + output.size());
    output.resize(distance(output.begin(), ip));
}

bool difference(vector<char> vec1, vector<char> vec2, vector<char> &output)
{
    bool flag = false;
    vector<char> tmp;
    output = vec1;
    crossing(vec1, vec2, tmp);
    int size = getSize(vec1, tmp);
    for (int iter = 0; iter < size; iter++)
    {
        size = output.size();
        for (int subIter = 0; subIter < size; subIter++)
        {
            if (output[iter] == tmp[subIter])
            {
                output.erase(output.begin() + iter);
                subIter = size;
                iter = 0;
                flag = true;
            }
        }
    }
    sort(output.begin(), output.end());
    return flag;
}
