class Solution
{
public:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &vis, int &node, int &ce)
    {
        vis[i] = 1;
        node++;
        ce += adj[i].size(); // undirect graph howay overlap korbe, jeta hobe din sheshe 2 gun.
        for (auto e : adj[i])
        {
            if (!vis[e])
            {
                dfs(adj, i, vis, node, ce);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int ccc = 0; // Complete connected Components
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int node = 0, ce = 0; // connected edge;
                dfs(adj, i, vis, node, ce);
                //  ce=(node*node-1)/2;
                // 2 bar kore jog hocche, modified dfs function e.
                if (ce == (node * (node - 1)))
                {
                    ccc++;
                }
            }
        }
        return ccc;
    }
};