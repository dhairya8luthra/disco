#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

void dfs(vector<vector<int>> &adjList, int node, unordered_set<int> &ancestors)
{
    ancestors.insert(node);

    for (int neighbor : adjList[node])
    {
        dfs(adjList, neighbor, ancestors);
    }
}

void findBounds(int n, int m, int x, int y, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; ++i)
    {
        addEdge(adjList, edges[i][0], edges[i][1]);
    }

    unordered_set<int> ancestorsX, ancestorsY;
    dfs(adjList, x, ancestorsX);
    dfs(adjList, y, ancestorsY);

    // Find Greatest Lower Bound (GLB)
    unordered_set<int> intersection;
    for (int ancestor : ancestorsX)
    {
        if (ancestorsY.count(ancestor))
        {
            intersection.insert(ancestor);
        }
    }

    // Find Least Upper Bound (LUB)
    int lub = -1;
    for (int ancestor : ancestorsX)
    {
        if (lub == -1 || ancestorsY.count(ancestor))
        {
            lub = ancestor;
            break;
        }
    }

    cout << "Greatest Lower Bound: " << *(intersection.begin()) << endl;
    cout << "Least Upper Bound: " << lub << endl;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    findBounds(n, m, x, y, edges);

    return 0;
}
