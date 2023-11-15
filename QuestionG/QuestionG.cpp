#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<int> &visited, vector<int> graph[], int start)
{
    visited[start] = 1;
    for (auto neighbour : graph[start])
    {
        if (!visited[neighbour])
        {
            dfs(visited, graph, neighbour);
        }
    }
}

int noOfComponents(int n, int m, vector<int> graph[])
{
    vector<int> visited(n, 0);
    int count = 0; // Initialize count to 0
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(visited, graph, i);
            count++;
        }
    }
    return count; // Return the count
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

    // outputing the ans
    int ans = noOfComponents(n, m, graph);
    cout << ans << endl;

    return 0;
}
