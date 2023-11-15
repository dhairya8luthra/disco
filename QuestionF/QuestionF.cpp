#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// DFS traversal to build topological ordering
void dfs(int node, vector<bool> &visited, unordered_set<int> prerequisites[], stack<int> &topoOrder)
{
    visited[node] = true;

    for (int pre : prerequisites[node])
    {
        if (!visited[pre])
        {
            dfs(pre, visited, prerequisites, topoOrder);
        }
    }

    topoOrder.push(node); // Add to ordering
}

// Topological sort
vector<int> topoSort(int numCourses, unordered_set<int> prerequisites[])
{

    vector<bool> visited(numCourses, false);
    stack<int> topoOrder;

    for (int i = 0; i < numCourses; ++i)
    {
        if (!visited[i])
        {
            dfs(i, visited, prerequisites, topoOrder);
        }
    }

    // Return topological order
    vector<int> order;
    while (!topoOrder.empty())
    {
        order.push_back(topoOrder.top());
        topoOrder.pop();
    }

    return order;
}

int main()
{

    int numCourses;
    cin >> numCourses;

    unordered_set<int> prerequisites[numCourses];

    bool flag = true;
    for (int i = 0; i < numCourses; ++i)
    {

        while (flag)
        {
            int pre;
            cin >> pre;
            prerequisites[i].insert(pre);

            if (pre == 0)
            {
                flag = false;
            }
        }

        flag = true;
    }

    vector<int> order = topoSort(numCourses, prerequisites);

    for (int course : order)
    {
        cout << course << " ";
    }

    return 0;
}