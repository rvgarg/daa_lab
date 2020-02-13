#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<list<pair<int, int>>> graph;
    int st, ds, wei;
    int edg, ver;
    cin >> ver >> edg;
    for (int i = 0; i < edg; i++)
    {
        cin >> st, ds, wei;
        graph[st].push_back(make_pair(ds, wei));
    }
    map<int, pair<int, pair<int, int>>> stpath;
    bool visited[ver + 1];
    for (int i = 0; i <= ver; i++)
    {
        stpath[i] = make_pair(-1, NULL);
        visited[i] = false;
    }
    int start;
    cout << "enter starting node ";
    cin >> start;
    stpath[start] = make_pair(0, NULL);
    visited[0] = true;
    bool all_visited = true;
    auto itr = stpath.begin();
    while (!all_visited)
    {
        all_visited = true;
        for (auto it = graph[itr->first].begin(); it != graph[itr->first].end(); it++)
        {
            if (visited[it->first])
            {
                if (stpath[it->first].first > (itr->first + it->second))
                {
                    stpath[it->first] = make_pair(itr->first + it->second, make_pair(itr->first, it->first));
                }
            }
            else
            {
                visited[it->first] = true;
                stpath[it->first] = make_pair(itr->first + it->second, make_pair(itr->first, it->first));
            }
        }
        itr++;
        for (int i = 0; i <= ver; i++)
        {
            if (visited[i] == false)
            {
                all_visited = false;
                break;
            }
        }
    }
    for (int i = 0; i <= ver; i++)
    {
        cout << i << " " << stpath[i].first << " (" << stpath[i].second.first << "," << stpath[i].second.second << ")" << endl;
    }
}