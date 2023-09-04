#include <iostream>
#include <algorithm>

using namespace std;
bool increment = true;

void printfence(string A[5][25],int row,int column)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<A[i][j] <<"  ";
        }
        cout<<"\n";
    }
    cout<< "-------------------------------------\n";
}
string segments(string plain_text, int key, int turn)
{
    string rail_fence[5][25],cypher_text;
    int index = 0, x=0, y=0;
    int row,column,i,j;

    row = key;
    column = plain_text.length();


    while(y<column)
    {
        while(increment)
        {
            while(x<row)
            {
                if(x==turn)
                {
                    cypher_text+=plain_text[index];
                    rail_fence[x][y] = plain_text[index];
                }
                x++;
                y++;
                index++;
            }

            increment = false;
        }
        x-=2;

        while(!increment)
        {

            while(x>=0)
            {
                if(x==turn)
                {
                    cypher_text+=plain_text[index];
                    rail_fence[x][y] = plain_text[index];
                }
                x--;
                y++;
                index++;
            }
            increment = true;
        }
        x+=2;


    }


    printfence(rail_fence,row,column);
    return cypher_text;
}

int main()
{
    string plain_text,cypher_text;
    int key, index = 0, x=0, y=0, turn = 0;
    int row,column, i, j;

    cout<< "Enter message : ";
    getline (cin,plain_text);

    cout<< "Enter key : ";
    cin>> key;

    plain_text.erase(remove(plain_text.begin(), plain_text.end(), ' '), plain_text.end());

    cout<<"\nRail-fence\n-------------------------------------\n";
    for(turn=0;turn<key;turn++)
        cypher_text+=segments(plain_text,key,turn);

    cypher_text.erase(remove(cypher_text.begin(), cypher_text.end(), ' '), cypher_text.end());

    cout <<"\nCypher Text: " << cypher_text <<"\n";

    return 0;
}

