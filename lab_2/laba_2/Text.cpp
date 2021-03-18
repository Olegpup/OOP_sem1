#include "Text.h"

Text::Text(Row row)
{
    _text_lenth = 1;
    _text_rows = new Row[1];
    _text_rows[0] = row;
}

Row* Text::copy_array(Row* copying_array, int array_lenth)
{
    Row* array_copy = new Row[array_lenth];
    for (int i = 0; i < array_lenth; i++)
    {
        array_copy[i] = copying_array[i];
    }

    return array_copy;
}

void Text::add_row_to_text(Row row)
{
    Row* text_rows_copy = new Row[_text_lenth];
    for (int i = 0; i < _text_lenth; i++)
    {
        text_rows_copy[i] = _text_rows[i];
    }
    _text_lenth++;
    _text_rows = new Row[_text_lenth];
    for (int i = 0; i < _text_lenth - 1; i++)
    {
        _text_rows[i] = text_rows_copy[i];
    }
    _text_rows[_text_lenth - 1] = row;
    delete[] text_rows_copy;
}

void Text::delete_row_from_text(int delete_number)
{
    _text_lenth--;
    for (int i = delete_number; i < _text_lenth; i++)
    {
        _text_rows[i] = _text_rows[i + 1];
    }
    Row* text_rows_copy = copy_array(_text_rows, _text_lenth);
    _text_rows = new Row[_text_lenth];
    _text_rows = copy_array(text_rows_copy, _text_lenth);
}

void Text::replace_row_in_text(int replace_number, Row row)
{
    _text_rows[replace_number] = row;
}

void Text::clean_text()
{
    _text_rows = nullptr;
    _text_lenth = 0;
}

int Text::get_text_lenth()
{
    return _text_lenth;
}

void Text::output_text()
{
    cout << endl;
    cout << "Your text:" << endl;
    cout << endl;
    for (int i = 0; i < _text_lenth; i++)
    {
        for (int j = 0; j < _text_rows[i].get_row_lenth(); j++)
        {
            char* chars = _text_rows[i].get_row_chars();
            cout << chars[j];
        }
        cout << endl;
    }
}

void Text::output_numeric_rows_in_text()
{
    cout << endl;
    cout << "Your text:" << endl;
    cout << endl;
    for (int i = 0; i < _text_lenth; i++)
    {
        if (_text_rows[i].is_row_numeric())
        {
            for (int j = 0; j < _text_rows[i].get_row_lenth(); j++)
            {
                char* chars = _text_rows[i].get_row_chars();
                cout << chars[j];
            }
            cout << endl;
        }
    }
}

char* input_char_array()
{
    string input_string;
    cin >> input_string;
    int input_string_lenth = input_string.length();
    char* char_array = new char[input_string_lenth + 1];
    for (int i = 0; i < input_string_lenth; i++)
    {
        char_array[i] = input_string[i];
    }
    char_array[input_string_lenth] = '\0';

    return char_array;
}