#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define test   \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int main()
{

    optimize();

    test
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];

        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[adj[i].size()]++;
        }

        int y = mp[1];
        int x = n - y - 1;

        y /= x;

        cout << x << " " << y << endl;
    }
    return 0;
}
