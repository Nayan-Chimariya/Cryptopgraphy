#include <iostream>
using namespace std;

void generateTable()
{
    char A[26][26];
    int i, j, k, l, m, diff=0;
    int x = 0, y;

    for(i=96;i<'z';i++)
    {
        k=i+1;
        y=-1;
        for(j=i+1;j<='z';j++)
        {
            y++;
            A[x][y] = j;
        }
        diff = i+1-97;

        for(m='a';diff!=0;m++)
        {
            y++;
            A[x][y] = m;
            diff--;
        }
        x++;
    }

    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            cout<<A[i][j] <<" ";
        }
        cout<<endl;
    }

}

int main()
{
    generateTable();
    return 0;
}

