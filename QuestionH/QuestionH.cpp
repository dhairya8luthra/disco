#include <iostream>
#include <vector>
using namespace std;
void dfs()
{
}
vector<int> cycle(vector<int> graph[], int n, int m)
{
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
    int ans = cycle(graph, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}