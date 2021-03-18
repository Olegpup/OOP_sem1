#include "Row.h";
#include "Text.h";

int main()
{
    cout << "Enter first row: " << endl;
    char* char_array = input_char_array();
    Row row = Row(char_array);
    Text text = Text(row);

    cout << "Press [0] to stop" << endl;
    cout << "Press [1] to add row into text" << endl;
    cout << "Press [2] to delete row from text" << endl;
    cout << "Press [3] to replace row in text" << endl;
    cout << "Press [4] to clean text" << endl;
    cout << "Press [5] to get size of text" << endl;
    cout << "Press [6] to get numeric row from text" << endl;

    bool continue_flag = true;
    while (continue_flag)
    {
        cout << "\nChoose action: " << endl;
        string action;
        cin >> action;

        if (action == "1")
        {
            cout << "Enter row to add:" << endl;
            char_array = input_char_array();
            row = Row(char_array);
            text.add_row_to_text(row);
            text.output_text();
        }
        else if (action == "2")
        {
            cout << "Enter row number to delete:" << endl;
            cout << endl;
            int delete_number;
            cin >> delete_number;
            text.delete_row_from_text(delete_number);
            text.output_text();
        }
        else if (action == "3")
        {
            cout << "Enter row number to replace:" << endl;
            int replace_number;
            cin >> replace_number;
            cout << "Enter row for replace:" << endl;
            char_array = input_char_array();
            row = Row(char_array);
            text.replace_row_in_text(replace_number, row);
            text.output_text();
        }

        else if (action == "4")
        {
            text.clean_text();
            text.output_text();
        }

        else if (action == "5")
        {
            int lenth = text.get_text_lenth();
            cout << "Size of your text: " << lenth << endl;
        }

        else if (action == "6")
        {
            text.output_numeric_rows_in_text();
        }

        else if (action == "0")
        {
            continue_flag = false;
        }
    }
}