#include <iostream>
using namespace std;

// прототипи функцій та процедур: 
void show_bin_form(int A);
void increment(int& number);
bool is_first_bigger(int A, int B);
int subtract(int A, int B);

int main()
{
    int A, B, C;
  
    cout << "Enter three numbers: ";
    cin >> A >> B >> C;
    cout << "Bin versions: " << endl;
    show_bin_form(A);
    show_bin_form(B);
    show_bin_form(C);
    if (is_first_bigger(A, B))
    {
        cout << A << " is bigger than " << B << endl;
    }
    else
    {
        cout << A << " isn't bigger than " << B << endl;
    }
    increment(A);
    increment(B);
    increment(C);
    cout << "Incremented first number: " << A << endl;
    cout << "Incremented second number: " << B << endl;
    cout << "Incremented third number: " << C << endl;
  
    return 0;
}

// функції та процедури:
void show_bin_form(int A)
{
    for (int i = 31; i >= 0; i--) // проходимо кожен біт (цифру) бінарного представлення числа
    {
        int A_bit = A & (1 << i); // використовуємо бітову маску бля кожного біту

        if (A_bit == 0)
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }
    }
    cout << endl;
}

void increment(int& A)
{

    A = subtract(0, ~A); // міняємо знак числа A з інвертованим двійковим представленням
}
 
bool is_first_bigger(int A, int B)
{
    int temp_1, temp_2;
    int result = 0;
    for (int i = 31; (i >= 0) && (result == 0); i--) // проходимо кожен біт (цифру) бінарного представлення числа
    {
        temp_1 = (A & (1 << i)) >> i; // виконуємо побітовий зсув вправо на i числа з застосованою бітовою маскою
        temp_2 = (B & (1 << i)) >> i;
        result = subtract(temp_1, temp_2);
    }
    if (result == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int subtract(int A, int B)
{
    while (B != 0)
    {
        int temp = (~A) & B; // інверсія бітів числа А І біти числа B

        A = A ^ B; // Виключаюче АБО

        B = temp << 1;
    }
    return A;
}