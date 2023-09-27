#include <iostream>
#include <cstring>

using namespace std;

char VTable[26][26];

void generateTable()
{
    int i, j, k, l, m, diff=0;
    int x = 0, y;

    for(i=96;i<'z';i++)
    {
        k=i+1;
        y=-1;
        for(j=i+1;j<='z';j++)
        {
            y++;
            VTable[x][y] = j;
        }
        diff = i+1-97;

        for(m='a';diff!=0;m++)
        {
            y++;
            VTable[x][y] = m;
            diff--;
        }
        x++;
    }
}

int main()
{
    char row, column;
    int Row, Column;
    int i = 0, j;
    string plain_text, cypher_text, key, vkey;

    cout<<"Enter message: ";
    cin>> cypher_text;

    cout<<"Enter key: ";
    cin>> key;

    int clen , klen, vklen;

    clen= cypher_text.length();
    klen = key.length();

    while(clen!=0)
    {
        vkey+=key[i];
        i++;
        if(i == klen)
            i = 0;
        clen--;
    }

    vklen = vkey.length();

    generateTable();

    for(i=0;vklen!=0;i++)
    {
        Row = vkey[i] % 97;
        for(j=0; j<25; j++)
        {
            if(VTable[Row][j]==cypher_text[i])
              break;
        }
        Column = vkey[j] % 97;
        plain_text += VTable[Row][Column];
        vklen--;
    }

    cout<<"\nPlain text : " <<plain_text <<endl;

    return 0;
}

