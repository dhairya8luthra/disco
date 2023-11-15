#include <iostream>
#include <vector>
#include <algorithm> // For find
using namespace std;

bool DFS(int node, int parent, vector<int> &color, vector<int> &parentArray, vector<int> graph[], vector<int> &cycle)
{
    color[node] = 1; // Mark the current node as visited

    for (int neighbor : graph[node])
    {
        if (color[neighbor] == 0)
        {
            // If the neighbor is not visited, recursively check for a cycle
            parentArray[neighbor] = node;
            if (DFS(neighbor, node, color, parentArray, graph, cycle))
                return true;
        }
        else if (neighbor != parent && color[neighbor] == 1)
        {
            // If the neighbor is visited and not the parent, a cycle is found
            // Construct and return the cycle
            int current = node;
            while (current != neighbor)
            {
                cycle.push_back(current + 1); // 1-based index
                current = parentArray[current];
            }
            cycle.push_back(neighbor + 1); // 1-based index
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    color[node] = 2; // Mark the current node as processed
    return false;
}

vector<int> cycle(vector<int> graph[], int n, int m)
{
    vector<int> color(n, 0);        // 0: unvisited, 1: visiting, 2: processed
    vector<int> parentArray(n, -1); // To keep track of the parent of each node
    vector<int> cycle;

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == 0 && DFS(i, -1, color, parentArray, graph, cycle))
        {
            // If the DFS detects a cycle starting from node i
            return cycle; // Return the constructed cycle
        }
    }

    // No cycle found
    return {-1};
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
    vector<int> ans = cycle(graph, n, m);
    if (ans.empty())
    {
        cout << "No cycle found." << endl;
    }
    else
    {
        cout << "Cycle found: ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
