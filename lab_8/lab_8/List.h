#pragma once

class Node
{
public:
    char value;
    Node* nextNode;
    Node(char value);
};


class List
{
private:
    int Length{};

public:
    Node* Start;
    Node* End;

    List();

    ~List();

    bool isEmpty();

    void AppendToStart(char value);

    Node* GetExclamationPoint();

    void DeleteA();

    void Show();
};