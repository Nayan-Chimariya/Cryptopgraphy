#include <iostream>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int SIZE = 5;

void Matrix(const string& keyword, char matrix[SIZE][SIZE])
{
    unordered_set<char> uniqueChars;
    int row = 0, col = 0;

    auto insertChar = [&](char c)
    {
        matrix[row][col++] = c;
        uniqueChars.insert(c);
        if (col == SIZE)
        {
            col = 0;
            row++;
        }
    };

    string key = keyword;
    key.erase(remove_if(key.begin(), key.end(), [&](char c) {
        if (isalpha(c) && !uniqueChars.count(toupper(c))) {
            insertChar(toupper(c));
        }
        return true;
    }), key.end());

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (c != 'J' && !uniqueChars.count(c))
            insertChar(c);
    }
}

void print(const char matrix[SIZE][SIZE])
{
    cout << "\nPlayfair Cipher Matrix:\n\n";
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    string keyword;
    char playfair[SIZE][SIZE];

    cout << "Enter the keyword for Playfair cipher: ";
    cin >> keyword;

    Matrix(keyword, playfair);
    print(playfair);

    return 0;
}

