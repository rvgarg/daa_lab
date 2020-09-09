#include <bits/stdc++.h>
using namespace std;
typedef long long int intll;
int32_t main()
{
    intll n;
    cin >> n;
    intll fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;
    for (intll i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] % 10000) + (fib[i - 2] % 100000);
    }
    cout << fib[n] % 10;
}