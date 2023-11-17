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

void markDFS(v(vi) arr, int n, int sv, v(bool) & visited, vi &path)
{
    visited[sv] = true;
    path.pb(sv);
    fr(i, 0, n)
    {
        if (!visited[i] && arr[sv][i] == 1)
        {
            markDFS(arr, n, i, visited, path);
        }
    }
}

void printMatch(vi arr, vi brr)
{
    rep(it, arr)
    {
        rep(jt, brr)
        {
            if (it == jt)
            {
                cout << it + 1;
                return;
            }
        }
    }
}

void solve()
{
    ll n, e;
    cin >> n >> e;
    ll x, y;
    cin >> x >> y;
    v(vi) gb(n, vi(n, 0)), lb(n, vi(n, 0));
    fr(i, 0, e)
    {
        ll f, s;
        cin >> f >> s;
        gb[f - 1][s - 1] = 1;
        lb[s - 1][f - 1] = 1;
    }
    vi g1, g2, l1, l2;
    v(bool) visited(n, false);
    markDFS(gb, n, x - 1, visited, g1);

    visited = v(bool)(n, false);
    markDFS(gb, n, y - 1, visited, g2);

    visited = v(bool)(n, false);
    markDFS(lb, n, x - 1, visited, l1);

    visited = v(bool)(n, false);
    markDFS(lb, n, y - 1, visited, l2);

    printMatch(l1, l2);
    cout << " ";
    printMatch(g1, g2);
    cout << nL;
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