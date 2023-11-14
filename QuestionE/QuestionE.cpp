#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<int> graph[], int n, int m, int start)
{
    vector<int> color(n, -1);
    color[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];

    // Taking input and making the adjacency list
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v - 1].push_back(u - 1);
        graph[u - 1].push_back(v - 1);
    }

    if (isBipartite(graph, n, m, 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
