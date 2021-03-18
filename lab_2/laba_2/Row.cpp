#include "Row.h"

Row::Row()
{
    _row_lenth = 0;
    _row_chars = nullptr;
}

Row::Row(char* char_array)
{
    _row_lenth = get_char_array_lenth(char_array);
    _row_chars = new char[_row_lenth + 1];

    for (int i = 0; i < _row_lenth; i++)
    {
        _row_chars[i] = char_array[i];
    }
    _row_chars[_row_lenth] = '\0';

}

int Row::get_char_array_lenth(char* char_array)
{
    int i = 0;
    while (char_array[i] != '\0')
    {
        i++;
    }

    return i;
}

int Row::get_row_lenth()
{
    return _row_lenth;
}

char* Row::get_row_chars()
{
    return _row_chars;
}

bool Row::is_row_numeric()
{
    bool result = true;
    for (int i = 0; i < _row_lenth; i++)
    {
        if (_row_chars[i] < '0' || _row_chars[i] > '9')
        {
            result = false;
        }
    }

    return result;
}