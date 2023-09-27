#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string encrypt(string plain_text, string key)
{
    string cypher_text, vkey;

    int plen , klen, vklen;

    plain_text.erase(remove(plain_text.begin(), plain_text.end(), ' '), plain_text.end());

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

    for(i=0;vklen!=0;i++)
    {
        char ch = ((plain_text[i]-97+vkey[i]-97 ) %26) + 97;
        cypher_text += ch;
        vklen--;
    }

    return cypher_text;
}

int main()
{
    string plain_text, cypher_text, key;

    cout<<"Enter message: ";
    getline(cin,plain_text);

    cout<<"Enter key: ";
    cin>> key;

    cypher_text = encrypt(plain_text,key);

    cout<<"\nCypher Text = " <<cypher_text <<endl;

    return 0;
}
