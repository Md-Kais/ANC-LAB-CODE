#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[123456];
bool vis[123456] = {false};
vector<int> friends;
void dfs(int source)
{
    vis[source] = 1;
    friends.push_back(source);
    for(auto e: adj[source]){
        if(vis[e]==0){
            dfs(e);
        }
    }
}
int main()
{

    int n, m; // n->nodes,m->edges
    cin >> n >> m;
    ll cost[n + 1]={}; // path cost.
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            friends.clear();
            dfs(i);
            ll mini = INT_MAX;
            for (auto e : friends)
            {
                mini = min(mini, cost[e]);
            }
            ans += mini;
            mini=INT_MAX;
            friends.clear();
        }
    }
    cout << ans << endl;

    return 0;
}
