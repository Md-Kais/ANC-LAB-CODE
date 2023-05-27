#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 5;
int n, w[M], c[M], S, W;
long long dp[35][4 * M];
int main()
{
    cin>>n>>s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> c[i];
        W = max(w[i], W);
    }
    int K = 0;

    memset(dp, -63, sizeof(dp));
    while ((S >> K) > 0)
        K++;
    dp[K][2 * W] = 0;
    for (int i = 2 * W; i <= 4 * W; i++)
    {
        long long v = -1e18;
        for (int j = 1; j <= n; j++)
        {
            if (i >= w[j])
            {
                dp[K][i] = max(dp[K][i], dp[K][i - w[j]] + c[j]);
            }
        }
    }
    K--;

    while (K >= 0)
    {
        for (int i = -2 * W; i <= 2 * W; i++)
        {
            int p = (S >> K) + i;
            if (p < 0)
                continue;
            for (int x = p / 2 - W; x <= p / 2 + W; x++)
            {
                // x-(S>>(K+1))+2*W
                dp[K][i + 2 * W] = max(dp[K][i + 2 * W], dp[K + 1][x - (S >> (K + 1)) + 2 * W] + dp[K + 1][p - x - (S >> (K + 1)) + 2 * W]);
            }
        }
        K--;
    }
    long long ans = 0;
    for (int i = 0; i <= 2 * W; i++)
        ans = max(ans, dp[0][i]);
    cout << ans << endl;
    return 0;
}