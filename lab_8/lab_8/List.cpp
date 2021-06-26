#include "List.h"
#include <iostream>


Node::Node(char value)
{
    this->value = value;
    nextNode = nullptr;
}


List::List()
{
    Start = nullptr;
    End = nullptr;
}


List::~List()
{
    Node* curNode = Start;
    Node* nodeToDelete;
    int tempLength = Length;

    while (tempLength)
    {
        nodeToDelete = curNode;
        curNode = curNode->nextNode;
        delete nodeToDelete;
        tempLength--;
    }
}


bool List::isEmpty()
{
    return End == nullptr;
}


void List::AppendToStart(char value)
{
    Node* node = new Node(value);

    if (isEmpty())
    {
        Start = node;
        End = node;
        Length++;
    }
    else
    {
        Node* tempNode = Start;

        Start = node;
        Start->nextNode = tempNode;
        Length++;
    }
}


void List::Show()
{
    if (Length > 0)
    {
        Node* currentNode = Start;
        int tempLength = Length;
        while (tempLength)
        {
            std::cout << currentNode->value << " ";
            currentNode = currentNode->nextNode;
            tempLength--;
        }
    }
    std::cout << std::endl << std::endl;
}


Node* List::GetExclamationPoint()
{
    int tempLength = Length;
    Node* currentNode = Start;
    while (tempLength)
    {
        if (currentNode->value == '!')
        {
            return currentNode;
        }
        currentNode = currentNode->nextNode;
        tempLength--;
    }
    return nullptr;
}


void List::DeleteA()
{
    Node* currentNode = Start;
    Node* previousNode = nullptr;
    int tempLength = Length;

    Node* nodeToDelete;

    while (tempLength)
    {
        if (currentNode->value == 'a' && previousNode == nullptr)
        {
            nodeToDelete = Start;
            currentNode = Start->nextNode;
            Start = Start->nextNode;
            delete nodeToDelete;

            Length--;
        }
        else if (currentNode->value == 'a' && currentNode->nextNode == nullptr)
        {
            nodeToDelete = End;
            End = previousNode;
            End->nextNode = nullptr;
            delete nodeToDelete;
            Length--;
        }
        else if (currentNode->value == 'a')
        {
            nodeToDelete = currentNode;

            currentNode = currentNode->nextNode;
            previousNode->nextNode = currentNode;

            delete nodeToDelete;
            Length--;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        tempLength--;
    }
}