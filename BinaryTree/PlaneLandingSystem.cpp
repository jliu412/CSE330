#include "BinarySearchTree.h"
#include "PlaneLandingSystem.h"

BinarySearchTree bst;

void requestLanding(int K, int key, string data)
{
    if (bst.isEmpty())
    {
        bst.insertNode(key, data);
        return;
    }

    if (abs(bst.findMax(bst.root)->key - key) < K)
    {
        cout << endl;
        cout << " E: Time Gap Less Than " << K << endl;
        return;
    }

    bst.insertNode(key, data);
}

void withdrawLandingRequest(int key, string data)
{
    if (!bst.isEmpty() && bst.searchNode(bst.root, key, data))
        bst.deleteNode(bst.searchNode(bst.root, key, data));
    else
        cout << " E: No Such Request " << endl;
}

void listLandingTimesAndFlightNumber()
{
    bst.inorderTraversal(bst.root);
}

void PLS()
{
    int choice, K, key;
    string data;

    cout << endl;
    cout << " Enter the Time Gap (int value) : ";
    cin >> K;

    while (true)
    {
        cout << endl;
        cout << endl;
        cout << " Plane Landing System " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Request Landing " << endl;
        cout << " 2. Withdraw Landing Request " << endl;
        cout << " 3. List Landing Times and Flight Number " << endl;
        cout << " 4. Return to Main Menu " << endl;
        cout << " Enter your choice : ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl;
            cout << " Enter landing time (int value) to be requested : ";
            cin >> key;
            cout << " Enter flight number (int value) to be requested : ";
            cin >> data;
            requestLanding(K, key, data);
            break;

        case 2:
            cout << endl;
            cout << " Enter landing time (int value) to be withdrew : ";
            cin >> key;
            cout << " Enter flight number (int value) to be withdrew : ";
            cin >> data;
            withdrawLandingRequest(key, data);
            break;

        case 3:
            cout << "  Landing Times and Flight Number  " << endl;
            cout << " -------------------" << endl;
            listLandingTimesAndFlightNumber();
            break;

        case 4:
            return;

        default:
            cout << " E: Invalid Choice ";
        }
    }
}