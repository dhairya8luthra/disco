#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isGraphic(vector<int> degrees, int n)
{
    if (n == 0)
    {
        cout << "YES";
        return 1;
    }
    flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] > n - 1)
        {
            cout << "NO";
            return -1;
        }
        if (degrees[i] < 0)
        {
            cout << "NO";
            return -1;
        }
        if (degrees[i] > 0)
        {
            flag = 0;
        }

        if (flag == = 1)
        {
            cout << "YES";
        }
        if (flag == 0)
        {
            int head = degrees[0];
            degrees.erase(degrees.begin());
            for (int i = 0; i < head; i++)
            {
                degrees[i]--;
            }
            sort(degrees.begin(), degrees.end(), greater<int>());
            isGraphic(degrees, n - 1);
        }
    }
}

void dfs(vector<int> graph[], int n, int u, int v, vector<int> vis, vector<int> path)
{
    if (u == v)
    {
        return;
    }
    for (auto it : graph[u])
    {
        while (!visited[it])
        {
            dfs() if (path.back == v)
            {
                return;
            }
        }
    }
    path.pop_back()
}

bool isBipartitie(vector<int> graph[n], int n, int m, int start)
{
    vector<int> color(n, -1);
    queue<int> q;
    color[start] = 1;
    queue.push(start);
    while (!queue)
    {
        int node = queue.front();
        queue.pop();
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] == 1 - color[node];
                queue.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

vector<int> topoSort(vector < int graph[n], vector<int> visited, int n)
{
    stack<int> s;
    bool visited[n] = {false};
}

vector<int> shortestPath(vector<int> graph[], int n, int m, int start)
{
    vector<int> dist(n, 1e9);
    vector<int> ans(n, -1);
    queue<int> q;
    q.push(start);
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
}

int main()
{
}