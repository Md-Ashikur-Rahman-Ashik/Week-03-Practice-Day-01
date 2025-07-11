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

void insertAtTail(Node *&head, Node *&tail, int desiredInput)
{
    Node *newNode = new Node(desiredInput);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextPointer = newNode;
        newNode->previousPointer = tail;
        tail = newNode;
    }
}

void sortAscending(Node *head)
{
    Node *tmp = head;
    for (Node *i = tmp; i->nextPointer != NULL; i = i->nextPointer)
    {
        for (Node *j = i->nextPointer; j != NULL; j = j->nextPointer)
        {
            if (i->integerValue > j->integerValue)
            {
                swap(i->integerValue, j->integerValue);
            }
        }
    }
}

void printForward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->nextPointer;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int inputValue;
    while (true)
    {
        cin >> inputValue;
        if (inputValue == -1)
        {
            break;
        }
        else
        {
            insertAtTail(head, tail, inputValue);
        }
    }

    sortAscending(head);
    printForward(head);

    return 0;
}