#include "Lines.h"

BigLetters::BigLetters(const char* str)
{
    data = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(str) + 1; i++)
    {
        data[i] = str[i];
    }
}

int BigLetters::GetLength()
{
    int counter = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        counter++;
    }

    return counter;
}

char* BigLetters::Sort()
{
    for (int i = 1; i < GetLength(); i++)
    {

        for (int j = i - 1; j >= 0 && data[j] > data[j + 1]; j--)
        {
            std::swap(data[j], data[j + 1]);
        } 
    }

    return data;
}


SmallLetters::SmallLetters(const char* str)
{
    data = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(str) + 1; i++)
    {
        data[i] = str[i];
    }
}

int SmallLetters::GetLength()
{
    int counter = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        counter++;
    }

    return counter;
}

char* SmallLetters::Sort()
{
    for (int i = 1; i < GetLength(); i++)
    {

        for (int j = i - 1; j >= 0 && data[j] < data[j + 1]; j--)
        {
            std::swap(data[j], data[j + 1]);
        }
    }

    return data;
}