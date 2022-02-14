#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void input(string in, vector<char> &vec)
{
    cout << "input new arr: \n";
    cin >> in;
    sort(in.begin(), in.end());
    for (int i = 0; i < in.size(); i++)
    {
        vec.push_back(in[i]);
    }
    in.clear();
    cout << '\n';
}

void printVec(vector<char> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << '\n';
}
int main()
{
    string inputString;
    vector<char> vecA, vecB, vecC;
    input(inputString, vecA);
    input(inputString, vecB);
    input(inputString, vecC);

    cout << "'A' arr: ";
    printVec(vecA);
    cout << "'B' arr: ";
    printVec(vecB);
    cout << "'C' arr: ";
    printVec(vecC);

    system("pause");
}