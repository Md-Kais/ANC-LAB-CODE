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
        string s;
        cin >> s;

        int l = 0, x = 0;
        ll y= stol(s);
        if (y > 0)
        {
            x += (y % 2020);
            l = ((y - (y % 2020)) / 2020);
            if(l>=x){
                l-=x;
            }
        }
        cerr<<x<<" "<<l<<endl;
        ll ans = 2021 * x + 2020 * l;
   
        ll check = stol(s);
        if (check == ans && (x + l > 0) && (x>=0 && l>=0))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
