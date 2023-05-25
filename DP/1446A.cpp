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
        ll n, w;
        cin >> n >> w;
        ll wt[n + 1];
        multimap<int, int, greater<int>> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> wt[i];
            m.insert({wt[i], i});
        }
        ll ww = w;

        vector<int> ans;
        for (auto e : m)
        {
            if (e.first <= w)
            {
                w -= e.first;
                ans.push_back(e.second);
            }
        }
        if (w <= (ww / 2))
        {
            cout << ans.size() << endl;
            for (auto e : ans)
            {
                cout << e << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
