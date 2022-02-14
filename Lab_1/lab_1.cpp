#include "functions.h"

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