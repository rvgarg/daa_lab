#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int, pair<int, int>> graph, mst;
    int edges, vertices;
    cout << "Enter No of edges in the map " << endl;
    cin >> edges >> vertices;
    int parent[vertices+1];
    for (int i = 0; i <= vertices; i++)
    {
        parent[i] = -1; 
    }
    
    for (int i = 0; i < edges; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.insert(pair<int, pair<int, int>>(c, make_pair(a, b)));
    }
    cout << "entered data :- " << endl;
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        cout << i->second.first << " " << i->second.second << " " << i->first << endl;
    }
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        if (parent[i->second.first] == parent[i->second.second] && parent[i->second.second] != -1)
        {
        }
        else
        {
            for (int j = 0; j <= vertices; j++)
            {
                if (j != i->second.first && j != i->second.second)
                {
                    if ((parent[j] == parent[i->second.first] || parent[j] == parent[i->second.second]) && parent[j] != -1)
                    {
                        cout << parent[j] << endl;
                        parent[j] = i->second.first;
                    }
                }
            }
            parent[i->second.first] = i->second.first;
            parent[i->second.second] = i->second.first;
            mst.insert({i->first, make_pair(i->second.first, i->second.second)});
        }
    }
    cout << endl;
    for (auto i = mst.begin(); i != mst.end(); i++)
    {
        cout << i->second.first << " " << i->second.second << " " << i->first << endl;
    }
    cout << "parent array ";
}