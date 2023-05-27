#include <bits/stdc++.h>
using namespace std;

vector<int> tree[123456];
int visited[123456];

int maxDistanceNode;
int maxDistance=0;

void dfs(int node, int distance)
{
    visited[node] = 1;

    if (distance > maxDistance)
    {
        maxDistance = distance;
        maxDistanceNode = node;
    }

    for (int neighbor : tree[node])
    {
        if (visited[node] == 0)
        {
            dfs(neighbor, distance + 1);
        }
    }
}

int findDiameter()
{

    maxDistanceNode = 0;
    maxDistance = 0;

    dfs(0, 0);

    maxDistance = 0;

    dfs(maxDistanceNode, 0);

    return maxDistance;
}

int main()
{
    // Example usage
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        tree[i].clear();
        visited[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int diameter = findDiameter();

    cout << "The diameter of the tree is: " << diameter << endl;

    return 0;
}
