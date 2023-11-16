#include <iostream>

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <pair>
using namespace std;

int main()
{ // taking input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n] for (int i = 0; i < m; i++)
    {
        int v, u, w;
        pair<int, int> edge1;
        pair<int, int> edge2;

        cin >> v >> u >> w;
        edge1.first = v - 1;
        edge1.secod = w;
        edge2.first = u - 1;
        edge2.second = w;
        graph[v - 1].push_back(edge2);
        graph[u - 1].push_back(edge1);
    }

    return 0;
}