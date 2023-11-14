#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<int> graph[], int n, int m, int start)
{
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    vector<int> ans(n, -1);
    queue<int> q;
    q.push(start); // Added the starting node to the queue

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : graph[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> ans = shortestPath(graph, n, m, 0);
    cout << ans[n - 1] << endl; // Added the missing semicolon and endl
    return 0;
}
