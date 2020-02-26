#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, max_weight;
    cout << "Enter number of items  ";
    cin >> num;
    cout << "Enter maaximum weight  ";
    cin >> max_weight;
    vector<pair<int, int>> items;
    cout << "Enter weight and benifit of the items " << endl;
    for (int i = 0; i < num; i++)
    {
        int weight, benifit;
        cin >> weight >> benifit;
        items.push_back(make_pair(weight, benifit));
    }
    sort(items.begin(), items.end());
    for (auto i = items.begin(); i != items.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    int table[num + 1][max_weight + 1] = {0};
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j <= max_weight; j++)
        {
            if (i == 0 || j == 0)
            {
                // cout << 0 << " ";
                table[i][j] = 0;
            }
            else if (items[i].first <= j && items[i].second + table[i - 1][j - items[i].first])
            {
                table[i][j] = items[i].second + table[i - 1][j - items[i].first];
                // cout << table[i][j] << endl;
            }
            else
            {
                table[i][j] = table[i - 1][j];
                // cout << table[i][j] << endl;
            }
        }
    }
    cout << table[num][max_weight] << endl;
    int W, i = max_weight;
    if(table[num][max_weight] > table[num][max_weight-1]){
        W = max_weight;
    } else
    {
        while(table[num][i] == table[num][i-1]){
            i--;
        }
        W = i;
    }
    cout << W;
}