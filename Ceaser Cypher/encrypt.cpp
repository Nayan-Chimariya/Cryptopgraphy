#include <iostream>
using namespace std;

string upperlower(int ch, char check)
{
    string cypher;

    if((ch) > check)
        cypher+= ch- 26 ;
    else
        cypher+=ch;

    return cypher;
}

string encrpyt(string message, int key)
{
    int i,message_int;
    string cypher;

    for(i=0;i<message.length();i++)
    {
        message_int = message[i];

        if(message_int>=97 && message_int<=122)
            cypher+=upperlower(message_int+key,'z');

        else if(message_int>=65 && message_int<=90)
            cypher+=upperlower(message_int+key,'Z');
    }

    return cypher;
}

int main()
{
    string plain_text, cypher_text;
    int key;

    cout<<"Enter your message : ";
    getline(cin,plain_text);

    cout<< "Enter key value : ";
    cin>> key;

    key %= 26;

    cypher_text = encrpyt(plain_text,key);

    cout<< "\nThe encrypted message is -> " <<cypher_text <<endl;

    return 0;
}
