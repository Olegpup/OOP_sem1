using System;

namespace lab_2_lib
{
    public class Row
    {
        private char[] _row_chars;
        private uint _row_lenth;

        public Row(char[] char_array)
        {
            _row_lenth = get_char_array_lenth(char_array);
            _row_chars = new char[_row_lenth + 1];
            for (uint i = 0; i < _row_lenth; i++)
            {
                _row_chars[i] = char_array[i];
            }
            _row_chars[_row_lenth] = '\0';
        }
        private uint get_char_array_lenth(char[] char_array)
        {
            uint i = 0;
            while (char_array[i] != '\0')
            {
                i++;
            }

            return i;
        }
        public uint get_row_lenth()
        {
            return _row_lenth;
        }
        public char[] get_row_chars()
        {
            return _row_chars;
        }
        public bool is_row_numeric()
        {
            bool result = true;
            for (uint i = 0; i < _row_lenth; i++)
            {
                if (_row_chars[i] < '0' || _row_chars[i] > '9')
                {
                    result = false;
                }
            }

            return result;
        }
    }
}