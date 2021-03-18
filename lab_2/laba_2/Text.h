#pragma once

#include <iostream>;
#include <string>;
#include "Row.h";

using namespace std;

class Text
{
private:
	Row* _text_rows;
	int _text_lenth;
	Row* copy_array(Row* copying_array, int array_lenth);

public:
	Text(Row row);
	void add_row_to_text(Row row);
	void delete_row_from_text(int delete_number);
	void replace_row_in_text(int replace_number, Row row);
	void clean_text();
	int get_text_lenth();
	void output_text();
	void output_numeric_rows_in_text();
};

char* input_char_array();