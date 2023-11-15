#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int node, vector<int> graph[], int &visited[], stack<int> &cycle)
{
}
vector<int> findCycle(vector<int> graph[], int n, int m)
{
    stack<int> cycle;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, cycle)
        }
    }
}
int main()
{
    // taking the graph as input
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
    // output
    int ans = findCycle(graph, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}