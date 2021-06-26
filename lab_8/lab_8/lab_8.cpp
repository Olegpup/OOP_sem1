#include <iostream>
#include "List.h"

using namespace std;


int main()
{
    List list = List();

    list.AppendToStart('q');
    list.AppendToStart('w');
    list.AppendToStart('e');
    list.AppendToStart('a');
    list.AppendToStart('a');
    list.AppendToStart('!');
    list.AppendToStart('a');
    list.AppendToStart('a');
    
    list.Show();

    Node* point = list.GetExclamationPoint();

    list.DeleteA();

    list.Show();
    cout << point->value;
}