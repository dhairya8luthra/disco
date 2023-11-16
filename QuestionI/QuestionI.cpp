#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int primAlgo(vector<pair<int, int>> graph[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[n] = {false};
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if (visited[node])
        {
            continue;
        }

        // add to the MST
        visited[node] = true;
        sum += wt;

        for (auto neighbour : graph[node])
        {
            // pushing neighbours to the priority queue
            int neighbour_vertice = neighbour.second;
            int neighbour_wt = neighbour.first;

            if (!visited[neighbour_vertice])
            {
                pq.push({neighbour_wt, neighbour_vertice});
            }
        }
    }

    return sum;
}

int main()
{
    // taking input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n];

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        pair<int, int> edge1, edge2;

        cin >> v >> u >> w;
        edge1.first = w;
        edge1.second = v - 1;
        edge2.first = w;
        edge2.second = u - 1;
        graph[v - 1].push_back(edge2);
        graph[u - 1].push_back(edge1);
    }

    // giving output
    cout << primAlgo(graph, n) << endl;

    return 0;
}
