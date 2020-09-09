#include <bits/stdc++.h>
using namespace std;
typedef long long int intll;
intll gcd(intll a, intll b)
{
    if (b == 0)
    {
        return a;
    }
    if (a == 0)
    {
        return b;
    }
    if (a > b)
    {
        return gcd(b, a % b);
    }
    else
    {
        return gcd(a, b % a);
    }
}
int32_t main()
{
    intll n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2);
}