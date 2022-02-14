#include "functions.h"
void taskList()
{
    cout << "\n1: A = (A \\ B) U (A n B)\n";
    cout << "2: (A \\ B) n (A n B)\n";
    cout << "3: (A \\ B) n B = NONE\n";
}
void task1(vector<char> vecA, vector<char> vecB)
{
    vector<char> diffvecAvecB;
    difference(vecA, vecB, diffvecAvecB); //(A \ B)
    vector<char> crossvecAvecB;
    crossing(vecA, vecB, crossvecAvecB); //(A n B)
    vector<char> taskOutput;
    unification(diffvecAvecB, crossvecAvecB, taskOutput);
    printVec(taskOutput);
}
int main()
{
    vector<char> vecA, vecB, vecC;
    input(vecA);
    input(vecB);
    input(vecC);
    system("cls");
    cout << "'A' arr: ";
    printVec(vecA);
    cout << "'B' arr: ";
    printVec(vecB);
    cout << "'C' arr: ";
    printVec(vecC);
    taskList();

    vector<char> diffvecAvecB;
    crossing(vecA, vecB, diffvecAvecB); //(A \ B)
    printVec(diffvecAvecB);

    system("pause");
}