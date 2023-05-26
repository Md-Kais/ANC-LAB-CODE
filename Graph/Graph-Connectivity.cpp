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
vector<int> adj[30];
bool vis[30] = {false};
ll ans;
void dfs(int s)
{
    vis[s] = 1;
    for (auto e : adj[s])
    {
        if (vis[e] == 0)
        {
            dfs(e);
        }
    }
    return;
}

int main()
{

    optimize();

    test
    {

        char x;
        cin >> x;
        int n = (x - 'A') + 1;
        cin.ignore(); // The cin.ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
        for (int i = 0; i <= 30; i++)
        {
            adj[i].clear();
            ;
            vis[i] = false;
        }
        string s;
        while (getline(cin, s) && s != "")
        {
            int u = s[0] - 'A' + 1;
            int v = s[1] - 'A' + 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                ans++;
                dfs(i);
            }
        }
        cout << ans << endl;
        if (tc)
            cout << endl;
    }
    return 0;
}
