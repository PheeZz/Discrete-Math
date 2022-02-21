#include "functions.h"
void taskList()
{
    cout << "\n1: A = (A \\ B) U (A n B)\n";
    cout << "2: (A \\ B) n (A n B)\n";
    cout << "3: (A \\ B) n B = NONE\n";
}
void task1(vector<char> vecA, vector<char> vecB)
{
    vector<char> diffResult;
    difference(vecA, vecB, diffResult); //(A \ B)
    vector<char> crossResult;
    crossing(vecA, vecB, crossResult); //(A n B)
    vector<char> taskOutput;
    unification(diffResult, crossResult, taskOutput);
    cout << "\nresult is: ";
    if (taskOutput.size() == 0)
    {
        cout << "NONE\n";
    }
    else
        printVec(taskOutput);
}
void task2(vector<char> vecA, vector<char> vecB)
{
    vector<char> diffResult;
    difference(vecA, vecB, diffResult); //(A \ B)
    vector<char> unificationResult;
    crossing(vecA, vecB, unificationResult); //(A n B)
    vector<char> taskOutput;
    crossing(diffResult, unificationResult, taskOutput); //(A \\ B) n (A n B)
    cout << "\nresult is: ";
    if (taskOutput.size() == 0)
    {
        cout << "NONE\n";
    }
    else
        printVec(taskOutput);
}
void task3(vector<char> vecA, vector<char> vecB)
{
    vector<char> diffResult;
    difference(vecA, vecB, diffResult); //(A \ B)
    vector<char> crossingResult;
    crossing(diffResult, vecB, crossingResult); //(A \\ B) n B
    cout << "\nresult is: ";
    if (crossingResult.size() == 0)
    {
        cout << "NONE\n";
    }
    else
        printVec(crossingResult);
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

    task1(vecA, vecB);
    task2(vecA, vecB);
    task3(vecA, vecB);

    system("pause");
}
