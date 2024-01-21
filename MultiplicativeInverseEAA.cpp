#include <iostream>
using namespace std;

int modInverse(int a, int m, int& x, int& y)
{
    if (m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = modInverse(m, a % m, x1, y1);

    x = y1;
    y = x1 - y1 * (a / m);

    return g;
}

int main()
{
    int a, m;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of m: ";
    cin >> m;

    int x, y;
    int inverse = modInverse(a, m, x, y);

    if (inverse == 1)
    {
        x = (x % m + m) % m;
        cout << "The multiplicative inverse of " << a << " modulo " << m << " is: " << x << "\n";
    }
    else
        cerr << "Inverse does not exist (a and m are not coprime)\n";

    return 0;
}

