#include <iostream>
using namespace std;

string upperlower(int ch, char check)
{
    string plain_text;

    if((ch) < check)
        plain_text+= ch+ 26 ;
    else
        plain_text+=ch;

    return plain_text;
}

string decrpyt(string cypher_text, int key)
{
    int i,cypher_int;
    string cypher;

    for(i=0;i<cypher_text.length();i++)
    {
        cypher_int = cypher_text[i];

        if(cypher_int>=97 && cypher_int<=122)
            cypher+=upperlower(cypher_int-key,'a');

        else if(cypher_int>=65 && cypher_int<=90)
            cypher+=upperlower(cypher_int-key,'A');
    }

    return cypher;
}

int main()
{
    string cypher_text, plain_text;
    int key;

    cout<<"Enter cypher message : ";
    getline(cin,cypher_text);

    cout<< "Enter key value : ";
    cin>> key;

    key %= 26;

    plain_text = decrpyt(cypher_text,key);

    cout<< "\nThe decrypted message is -> " <<plain_text <<endl;

    return 0;
}
