#include <iostream>
#include <cmath>
using namespace std;

int power(int x, int y, int p) 
{
    int result = 1;
    x = x % p;
    while (y > 0) 
    {
        if (y & 1)
            result = (result * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

bool isPrimitiveRoot(int g, int p) 
{
    for (int i = 2; i <= sqrt(p - 1); i++) 
    {
        if ((p - 1) % i == 0) 
        {
            if (power(g, (p - 1) / i, p) == 1 || power(g, i, p) == 1)
                return false;
        }
    }
    return true;
}

int main() 
{
    int prime, primitiveRoot;
    cout << "Enter prime number (p): ";
    cin >> prime;
    cout << "Enter potential primitive root (g): ";
    cin >> primitiveRoot;

    if (isPrimitiveRoot(primitiveRoot, prime))
        cout << primitiveRoot << " is a primitive root modulo " << prime << endl;
    else
        cout << primitiveRoot << " is not a primitive root modulo " << prime << endl;

    return 0;
}
