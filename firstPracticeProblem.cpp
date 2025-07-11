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

void insertAtTail(Node *&head, Node *&tail, int integerValue)
{
    Node *newNode = new Node(integerValue);
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

int checkSize(Node *head)
{
    Node *tmp = head;
    int count = 0;

    while (tmp != NULL)
    {
        count++;
        tmp = tmp->nextPointer;
    }

    return count;
}

int main()
{
    Node *firstHead = NULL;
    Node *firstTail = NULL;

    int firstInput;
    while (true)
    {
        cin >> firstInput;
        if (firstInput == -1)
        {
            break;
        }
        else
        {
            insertAtTail(firstHead, firstTail, firstInput);
        }
    }

    Node *secondHead = NULL;
    Node *secondTail = NULL;

    int secondInput;
    while (true)
    {
        cin >> secondInput;
        if (secondInput == -1)
        {
            break;
        }
        else
        {
            insertAtTail(secondHead, secondTail, secondInput);
        }
    }

    int firstSize = checkSize(firstHead);
    int secondSize = checkSize(secondHead);

    if (firstSize == secondSize)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}