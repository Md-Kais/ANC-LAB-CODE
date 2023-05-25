#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int M, C, K, price[25][25]; // price[garment_id (<= 20)][model (<= 20)]
int memo[210][25];          // dp table memo[money (<= 200)][garment_id (<= 20)]

int shop(int money, int garment_id)
{
    if (money < 0)
        return -1 * INT_MAX; // fail, return a large negative number (1B)

    if (garment_id == C)  // we have bought last garment
        return M - money; // done, return this value

    if (memo[money][garment_id] != -1)  // if this state has been visited before
        return memo[money][garment_id]; // simply return it

    int max_value = -1 * INT_MAX;

    for (int model = 1; model <= price[garment_id][0]; model++) // try all possible models
        max_value = max(max_value, shop(money - price[garment_id][model], garment_id + 1));

    return memo[money][garment_id] = max_value; // assign max_value to dp table + return it!
}

#define test   \
    int tc;    \
    cin >> tc; \
    while (tc--)

int main()
{

   
    test
    {
        cin >> M >> C;

        for (int i = 0; i < C; i++)
        {
            cin >> K;

            price[i][0] = K;

            for (int j = 1; j <= K; j++)
                cin >> price[i][j];
        }
        memset(memo, -1, sizeof memo); // initialize DP memo table

        ll score = shop(M, 0); // start the top-down DP

        if (score < 0)
            cout<<"no solution"<<endl;
        else
            cout<<score<<endl;
    }
    return 0;
}
// 3 100 4 3 8 6 4 2 5 10 4 1 3 3 7 4 50 14 23 8 20 3 3 4 6 8 2 5 10 4 1 3 5 5 5 3 3 6 4 8 2 10 6 4 7 3 1 7