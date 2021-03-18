using System;

namespace lab_2_lib
{
    public class Text
    {
        private Row[] _text_rows;
        private uint _text_lenth;

        public Text(Row row)
        {
            _text_lenth = 1;
            _text_rows = new Row[1];
            _text_rows[0] = row;
        }
        private Row[] copy_array(Row[] copying_array, uint array_lenth)
        {
            Row[] array_copy = new Row[array_lenth];
            for (uint i = 0; i < array_lenth; i++)
            {
                array_copy[i] = copying_array[i];
            }
            return array_copy;
        }
        public void add_row_to_text(Row row)
        {
            Row[] text_rows_copy = new Row[_text_lenth];
            for (uint i = 0; i < _text_lenth; i++)
            {
                text_rows_copy[i] = _text_rows[i];
            }
            _text_lenth++;
            _text_rows = new Row[_text_lenth];
            for (uint i = 0; i < _text_lenth - 1; i++)
            {
                _text_rows[i] = text_rows_copy[i];
            }
            _text_rows[_text_lenth - 1] = row;
        }
        public void delete_row_from_text(int delete_number)
        {
            _text_lenth--;
            for (int i = delete_number; i < _text_lenth; i++)
            {
                _text_rows[i] = _text_rows[i + 1];
            }
            Row[] text_rows_copy = copy_array(_text_rows, _text_lenth);
            _text_rows = new Row[_text_lenth];
            _text_rows = copy_array(text_rows_copy, _text_lenth);
        }
        public void replace_row_in_text(int replace_number, Row row)
        {
            _text_rows[replace_number] = row;
        }
        public void clean_text()
        {
            _text_rows = null;
            _text_lenth = 0;
        }
        public uint get_text_lenth()
        {
            return _text_lenth;
        }
        public void output_text()
        {
            Console.WriteLine();
            Console.WriteLine("Your text:");
            Console.WriteLine();
            for (uint i = 0; i < _text_lenth; i++)
            {
                for (uint j = 0; j < _text_rows[i].get_row_lenth(); j++)
                {
                    char[] chars = _text_rows[i].get_row_chars();
                    Console.Write(chars[j]);
                }
                Console.WriteLine();
            }
        }
        public void output_numeric_rows_in_text()
        {
            Console.WriteLine();
            Console.WriteLine("Numeric rows:");
            Console.WriteLine();
            for (uint i = 0; i < _text_lenth; i++)
            {
                if (_text_rows[i].is_row_numeric())
                {
                    for (uint j = 0; j < _text_rows[i].get_row_lenth(); j++)
                    {
                        char[] chars = _text_rows[i].get_row_chars();
                        Console.Write(chars[j]);
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}