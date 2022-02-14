#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> //для ф-ии sort
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
    cout << ".\n";
}

int getSize(vector<char> &vec1, vector<char> &vec2)
{
    int size = 0;
    if (vec1.size() > vec2.size())
    {
        size = vec1.size();
        vec2.resize(vec1.size()); // resize вектора для устранения ошибки выхода за границы массива в дальнейшем
    }
    else
    {
        size = vec2.size();
        vec1.resize(vec2.size()); // resize вектора для устранения ошибки выхода за границы массива в дальнейшем
    };
    return size;
}
bool crossing(vector<char> vec1, vector<char> vec2, vector<char> &output)
{
    int size = getSize(vec1, vec2);
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size; j++)
        {
            if (vec1[i] == vec2[j])
            {
                output.push_back(vec1[i]);
                flag = true;
            }
        }
    }
    return flag;
}

bool isNotExist(vector<char> output, char symbol) //вспомогательная функция для проверки наличия в множестве
{
    bool flag = true;
    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] == symbol)
        {
            flag == false;
        }
    }
    return flag;
}

bool unification(vector<char> vec1, vector<char> vec2, vector<char> &output)
{
    int size = getSize(vec1, vec2);
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (vec1[i] == vec2[j])
            {
                if (isNotExist(output, vec1[i]))
                {
                    output.push_back(vec1[i]);
                    flag = true;
                }
            }
        }
    }
    return flag;
}

bool difference(vector<char> vec1, vector<char> vec2, vector<char> &output)
{
    bool flag = false;
    vector<char> tmp;
    if (crossing(vec1, vec2, tmp))
    {
        int size = getSize(vec1, tmp);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; i < size; j++)
            {
                if (vec1[i] == tmp[j])
                {
                    output.push_back(vec1[i]);
                    flag = true;
                }
            }
        }
    }
    return flag;
}
