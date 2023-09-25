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

string encrypt(string plain_text, string key)
{
    int Row, Column;
    string cypher_text, vkey;

    int plen , klen, vklen;

    plen= plain_text.length();
    klen = key.length();

    int i = 0;

    while(plen!=0)
    {
        vkey+=key[i];
        i++;
        if(i == klen)
            i = 0;
        plen--;
    }

    vklen = vkey.length();

    generateTable();

    for(i=0;vklen!=0;i++)
    {
        Row = plain_text[i] % 97;
        Column = vkey[i] % 97;
        cypher_text += VTable[Row][Column];
        vklen--;
    }

    return cypher_text;
}


int main()
{
    string plain_text, cypher_text, key;

    cout<<"Enter message: ";
    cin>> plain_text;

    cout<<"Enter key: ";
    cin>> key;

    cypher_text = encrypt(plain_text,key);

    cout<<"\nCypher Text = " <<cypher_text <<endl;

    return 0;
}

