#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *previousPointer;
    Node *nextPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->previousPointer = NULL;
        this->nextPointer = NULL;
    }
};

int checkSize(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->nextPointer;
    }

    return count;
}

void insertAtAnyPosition(Node *&head, Node *&tail, int desiredValue, int desiredIndex)
{
    Node *newNode = new Node(desiredValue);

    if (desiredIndex == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->nextPointer = head;
            head->previousPointer = newNode;
            head = newNode;
            return;
        }
    }

    Node *tmp = head;
    for (int i = 0; i < desiredIndex - 1; i++)
    {
        tmp = tmp->nextPointer;
    }

    if (tmp == tail)
    {
        tail->nextPointer = newNode;
        newNode->previousPointer = tail;
        tail = newNode;
        return;
    }

    newNode->nextPointer = tmp->nextPointer;
    tmp->nextPointer->previousPointer = newNode;
    tmp->nextPointer = newNode;
    newNode->previousPointer = tmp;
}

void printForward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->nextPointer;
    }

    cout << endl;
}

void printBackward(Node *head)
{
    Node *tmp = head;
    if (tmp == NULL)
    {
        return;
    }

    printBackward(tmp->nextPointer);
    cout << tmp->integerValue << " ";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int inputQuery;
    cin >> inputQuery;

    for (int i = 0; i < inputQuery; i++)
    {
        int inputValue, desiredIndex;
        cin >> desiredIndex >> inputValue;

        int countSize = checkSize(head);
        if (desiredIndex > countSize && desiredIndex != 0)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insertAtAnyPosition(head, tail, inputValue, desiredIndex);
            printForward(head);
            printBackward(head);
            cout << endl;
        }
    }

    return 0;
}