#include "BinarySearchTree.h"
#include "PlaneLandingSystem.h"

int main()
{
    int choice;
    while (true)
    {
        cout << endl;
        cout << " Homework 4 " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Binary Search Tree " << endl;
        cout << " 2. Plane Landing System " << endl;
        cout << " 3. Exit " << endl;
        cout << " Enter your choice : ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            BST();
            break;

        case 2:
            PLS();
            break;

        case 3:
            return 0;
            break;
        default:
            cout << " E: Invalid Choice ";
        }
    }
}