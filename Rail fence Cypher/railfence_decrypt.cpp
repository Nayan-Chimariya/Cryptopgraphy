#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
int index = 0;
bool increment = true;

void printfence(string A[5][100], int row, int column)
{
    int i, j, line_width;
    string line;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            cout << A[i][j] << setw(5);

        cout << "\n\n\n";
        line_width = column * 5;
        line = string(line_width, '-');
        cout << line << endl;
    }

}

string decrypt(string cypher_text, int key)
{
    int row, column;
    row=key;
    column = cypher_text.length();
    string rail_fence[5][100],  plain_text;
    int x = 0, y = 0;

    while (y < column)
    {
        while (increment)
        {
            while (x < row)
            {
                rail_fence[x][y] = " ";
                x++;
                y++;
            }
            increment = false;
        }
        x -= 2;

        while (!increment)
        {
            while (x >= 0)
            {
                rail_fence[x][y] = " ";
                x--;
                y++;
            }
            increment = true;
        }
        x += 2;
    }

    index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (rail_fence[i][j] == " " && index < column)
            {
                rail_fence[i][j] = cypher_text[index];
                index++;
            }
        }
    }

    increment = true;
    x = 0, y = 0;
    while (y < column)
    {
        while (increment)
        {
            while (x < row)
            {
                plain_text += rail_fence[x][y];
                x++;
                y++;
            }
            increment = false;
        }
        x -= 2;

        while (!increment)
        {
            while (x >= 0)
            {
                plain_text += rail_fence[x][y];
                x--;
                y++;
            }
            increment = true;
        }
        x += 2;
    }
    printfence(rail_fence, row, column);

    return plain_text;
}

int main()
{
    string cypher_text, plain_text,line;
    int key,line_width;

    cout << "Enter Cypher Text: ";
    getline(cin, cypher_text);

    cout << "Enter Key: ";
    cin >> key;

    cypher_text.erase(remove(cypher_text.begin(), cypher_text.end(), ' '), cypher_text.end());

    cout<<endl<<"Rail Fence is: "<<endl<<endl;
    line_width = cypher_text.length() * 5;
    line = string(line_width, '-');
    cout <<line<< endl;

    plain_text = decrypt(cypher_text, key);

    cout<<endl << "\nPlain Text for the  '"<<cypher_text<<"' is: " << plain_text << endl;
    cout<<endl;
    return 0;
}
