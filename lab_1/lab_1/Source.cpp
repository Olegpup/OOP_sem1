#include <iostream>
using namespace std;

// ��������� ������� �� ��������: 
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

// ������� �� ���������:
void show_bin_form(int A)
{
    for (int i = 31; i >= 0; i--) // ��������� ����� �� (�����) �������� ������������� �����
    {
        int A_bit = A & (1 << i); // ������������� ����� ����� ��� ������� ���

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

    A = subtract(0, ~A); // ������ ���� ����� A � ������������ �������� ��������������
}
 
bool is_first_bigger(int A, int B)
{
    int temp_1, temp_2;
    int result = 0;
    for (int i = 31; (i >= 0) && (result == 0); i--) // ��������� ����� �� (�����) �������� ������������� �����
    {
        temp_1 = (A & (1 << i)) >> i; // �������� �������� ���� ������ �� i ����� � ������������ ������ ������
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
        int temp = (~A) & B; // ������� ��� ����� � � ��� ����� B

        A = A ^ B; // ���������� ���

        B = temp << 1;
    }
    return A;
}