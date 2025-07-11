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

void insertAtTail(Node *&head, Node *&tail, int inputValue)
{
    Node *newNode = new Node(inputValue);
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

void checkPalindrome(Node *head, Node *tail)
{
    Node *tmp = head;
    int countSize = 0;
    while (tmp != NULL)
    {
        countSize++;
        tmp = tmp->nextPointer;
    }

    int count = 0;
    for (Node *i = head, *j = tail; j != i->previousPointer && i != j; i = i->nextPointer, j = j->previousPointer)
    {
        if (i->integerValue == j->integerValue)
        {
            count++;
        }
    }

    if (count == countSize / 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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

    checkPalindrome(head, tail);

    return 0;
}