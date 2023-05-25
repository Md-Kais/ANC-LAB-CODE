#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int wt[1005], val[1005];
long long dp[1005][100005];

long long func(int index, int val_left)
{
    if (val_left == 0)
        return 0;
    if (index < 0)
        return 1e12;
    if (dp[index][val_left] != -1)
        return dp[index][val_left];

    long long ans = func(index - 1, val_left);
    if (val_left - val[index] >= 0)
        ans = min(ans, func(index-1, val_left - val[index]) + wt[index]);
    return dp[index][val_left] = ans;
}
int main()
{

    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    int max_value=1e5;
    for(int i=max_value;i>=0;--i){
        if(func(n-1,i) <=w){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
