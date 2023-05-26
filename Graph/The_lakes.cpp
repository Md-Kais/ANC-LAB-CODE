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
int a[1010][1010] = {};
bool vis[1010][1010] = {false};
int n, m;

ll dfs(int i, int j)
{
    vis[i][j] = true;
    int ans= a[i][j];
    if (i != 0 && a[i - 1][j] != 0 && !vis[i - 1][j])
    {
        ans += dfs(i - 1, j);
    }
    if (j != 0 && a[i][j - 1] != 0 && !vis[i][j - 1])
    {
        ans += dfs(i, j - 1);
    }
    if (i != n && a[i + 1][j] != 0 && !vis[i + 1][j])
    {
        ans += dfs(i + 1, j);
    }
    if (j != m && a[i][j + 1] != 0 && !vis[i][j + 1])
    {
        ans += dfs(i, j + 1);
    }
    return ans;
}
int main()
{

    optimize();

    test
    {
        ll ans=0;
        
        cin >> n >> m;
        a[1010][1010] = {0};
       
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
                cin >> a[i][j];
            }
        }
       
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && a[i][j] != 0)
                {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
