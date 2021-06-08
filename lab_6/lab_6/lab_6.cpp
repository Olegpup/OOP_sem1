#include "Lines.h"

int main()
{
    Lines* base_ptr;

    BigLetters b("QWERTY");
    SmallLetters s("abcd");

    base_ptr = &b;
    cout << "\nSorted line: " << base_ptr->Sort() << endl;
    cout<< "Length: " << base_ptr->GetLength() << endl;

    base_ptr = &s;
    cout << "\nSorted line: " << base_ptr->Sort() << endl;
    cout << "Length: " << base_ptr->GetLength() << endl;

    return 0;
}