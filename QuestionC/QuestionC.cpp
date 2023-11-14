#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &tree, int u, int v, vector<int> &path, vector<bool> &visited)
{
    visited[u] = true;
    path.push_back(u);

    if (u == v)
    {
        return;
    }

    for (int neighbor : tree[u])
    {
        if (!visited[neighbor])
        {
            dfs(tree, neighbor, v, path, visited);
            // If the destination is found, exit the loop
            if (path.back() == v)
            {
                return;
            }
        }
    }

    // Backtrack if the destination is not found in the current subtree
    path.pop_back();
}

int main()
{
    int n;
    cin >> n;

    // Create an adjacency list for the tree
    vector<vector<int>> tree(n + 1);

    // Input tree edges
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int start, destination;
    cin >> start >> destination;

    // Perform DFS to find the path from start to destination
    vector<int> path;
    vector<bool> visited(n + 1, false);
    dfs(tree, start, destination, path, visited);

    // Output the result
    cout << path.size() << endl;
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}
