#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int n, w; // item-type , capacity
    cin >> n >> w;
    int k[n + 1][w + 1] = {0};
    int wt[n + 1] = {0};  // weight
    int val[n + 1] = {0}; // value
    //taking input
    for (int i = 0; i < n; i++)
    {

        cin >> wt[i] >> val[i];
    }
    //Initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if(i==0 || j==0){
                k[i][j]=0;
            }
        }
    }
    //Unbounded knapsack
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                k[i][j] = max(val[i - 1] + k[i][j - wt[i - 1]], k[i - 1][j]);
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
        }
    }
    cout << k[n][w] << endl; // max profit

    return 0;
}
