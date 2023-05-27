#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define test   \
    int tc;    \
    cin >> tc; \
    while (tc--)

vector<int> adj[123456];
bool vis[123456] = {0};
set<int> fall;

void dfs(int source)
{
    vis[source] = 1;
    fall.insert(source);
    
    for (auto e : adj[source])
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

    test
    {
        int n, m, l; // n->nodes,m->edges , l is those nodes which is knocked by hand to fall.
        cin >> n >> m >> l;

        // thing about the dominos , they are connected in order to fall.

        for (int i = 0; i <= n; i++)
        {
            vis[i]= 0;
            adj[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // directed.
        }

        for (int i = 0; i < l; i++)
        {
            int x;
            cin >> x;
            if (vis[x] == 0)
            {
                dfs(x);
            }
        }

        cout << fall.size() << endl;
        fall.clear();
        
    }

    return 0;
}
