#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Lines
{
public:
	virtual int GetLength() = 0;
	virtual char* Sort() = 0;
};

class BigLetters : public Lines
{
private:
    char* data;
public:
    BigLetters(const char* str);
    int GetLength() override;
    char* Sort() override;
};

class SmallLetters : public Lines
{
private:
    char* data;
public:
    SmallLetters(const char* str);
    int GetLength() override;
    char* Sort() override;
};