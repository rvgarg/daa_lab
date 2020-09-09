#include <bits/stdc++.h>
using namespace std;
typedef long long int intll;
int main()
{
    intll n;
    cin >> n;
    int num[n + 2], sum[n + 2];
    num[0] = 0;
    sum[0] = 0;
    num[1] = 1;
    sum[1] = 1;
    for (intll i = 2; i < n + 1; i++)
    {
        num[i] = (num[i - 1] + num[i - 2]) % 10;
        sum[i] = (num[i] + sum[i-1]) % 10;
    }
    cout << sum[n];
}