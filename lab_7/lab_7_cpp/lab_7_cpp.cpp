#include <iostream>
#include <string>

using namespace std;

class WrongOperand : exception          //my own exception class
{
private:
    string text;
public:
    WrongOperand(string text)
    {
        this->text = text;
    }

    string Text()
    {
        return text;
    }
};

class Foo
{
private:     
    double a;        //values of numbers
    double b;
    double c;
    double d;

public:
    Foo() = default;

    Foo(double a, double b, double c, double d)        //polinom function
    {
        if (a == 4 || a <= 0)
        {
            throw WrongOperand("Value of a is invalid");
        }

        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    void SetA(double value)              //set functions
    {
        if (value == 4 || value <= 0)
        {
            throw WrongOperand("Value of a is invalid");        //throwing exception
        }

        a = value;
    }

    void SetB(double value)
    {
        b = value;
    }

    void SetC(double value)
    {
        c = value;
    }

    void SetD(double value)
    {
        d = value;
    }

    double GetA()              //get functions
    {
        return a;
    }

    double GetB()
    {
        return b;
    }

    double GetC()
    {
        return c;
    }

    double GetD()
    {
        return d;
    }

    double GetValue()
    {
        return (2 * c - d + sqrt(23 * a)) / (a / 4 - 1);
    }
};

int main()
{
    auto polynom1 = Foo();
    try 
    {
        double a;
        double b;
        double c;
        double d;

        cout << "Enter a: ";
        cin >> a;
        polynom1.SetA(a);

        cout << "Enter b: ";
        cin >> b;
        polynom1.SetB(b);

        cout << "Enter c: ";
        cin >> c;
        polynom1.SetC(c);

        cout << "Enter d: ";
        cin >> d;
        polynom1.SetD(d);

        auto polynom2 = Foo(12, 1, 3, 7);

        cout << "a, b, c, d" << endl;
        cout << polynom1.GetA() << " ";
        cout << polynom1.GetB() << " ";
        cout << polynom1.GetC() << " ";
        cout << polynom1.GetD() << " ";
        cout << polynom1.GetD() << " = " << polynom1.GetValue() << endl << endl;
        cout << "a, b, c, d" << endl;
        cout << polynom2.GetA() << " ";
        cout << polynom2.GetB() << " ";
        cout << polynom2.GetC() << " ";
        cout << polynom2.GetD() << " ";
        cout << polynom2.GetD() << " = " << polynom2.GetValue() << endl << endl;
    }
    catch (WrongOperand& exc)
    {
        cout << exc.Text();
    }
}