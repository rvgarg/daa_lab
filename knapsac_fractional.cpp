#include <bits/stdc++.h>
using namespace std;
bool sorter(pair<float, int> a, pair<float, int> b)
{
    return a.first > b.first;
}
int main()
{
    int max_wt, no_of_items;
    cout << "enter max weight ";
    cin >> max_wt;
    cout << "number of items ";
    cin >> no_of_items;
    vector<pair<float, int>> lis;
    cout << "enter weight and benifit of the items " << endl;
    for (int i = 0; i < no_of_items; i++)
    {
        int weight, benifit;
        cin >> weight >> benifit;
        float frac = (float)benifit / weight;
        lis.push_back({frac, weight});
    }
    sort(lis.begin(), lis.end(), sorter);
    for (auto i = lis.begin(); i != lis.end(); i++)
        cout << i->first << " " << i->second << endl;
    int cur_weight = 0, cur_benifit = 0;
    float cur_benifit_frac = 0, cur_weight_frac = 0;
    for (auto i = lis.begin(); i != lis.end(); i++)
    {
        if (cur_weight + i->second <= max_wt)
        {
            cur_benifit += (i->first * i->second);
            cur_weight += i->second;
        }
        else if(cur_weight_frac < max_wt)
        {
            cur_weight_frac = max_wt - cur_weight;
            cur_benifit_frac = cur_benifit + (cur_weight_frac * i->first);
            cur_weight_frac = max_wt;
            // break;
        }
    }
    cout << "maximum benefit gained in knapsac(0/1) is " << cur_benifit << endl;
    cout << "weight used is " << cur_weight << endl;
    cout << "maximum benefit gained in knapsac fractional is " << cur_benifit_frac << endl;
    cout << "weight used is " << max_wt << endl;
}