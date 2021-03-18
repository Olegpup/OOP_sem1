#pragma once

#include <iostream>;

using namespace std;

class Row
{
private:
	char* _row_chars;
	int _row_lenth;
	int get_char_array_lenth(char* char_array);
public:
	Row();
	Row(char* char_array);
	int get_row_lenth();
	char* get_row_chars();
	bool is_row_numeric();
};