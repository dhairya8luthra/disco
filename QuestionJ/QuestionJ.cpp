#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >= (a); i--)
#define rep(i, arr) for (auto i : arr)
#define nL "\n"

struct edge
{
    int s, d, w;
};

bool compare(struct edge e1, struct edge e2)
{
    return e1.w < e2.w;
}

int getParent(int n, vi &parent)
{
    if (parent[n] == n)
        return n;
    return getParent(parent[n], parent);
}

int kruskalAlgo(v(struct edge) arr, int n, int e)
{
    sort(all(arr), compare);
    vi parent(n, 0);
    fr(i, 0, n) parent[i] = i;
    ll minCost = 0, edges = 0, k = 0;
    while (edges < n - 1)
    {
        if (getParent(arr[k].s, parent) != getParent(arr[k].d, parent))
        {
            parent[arr[k].s] = arr[k].d;
            edges++;
            minCost += arr[k].w;
        }
        k++;
    }

    return minCost;
}

void solve()
{
    ll n, e;
    cin >> n >> e;
    v(struct edge) arr(e);
    fr(i, 0, e)
    {
        cin >> arr[i].s >> arr[i].d >> arr[i].w;
        arr[i].s -= 1, arr[i].d -= 1;
    }
    cout << kruskalAlgo(arr, n, e) << nL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    // cin>>t;

    while (t--)
    {
        solve();
    }
}