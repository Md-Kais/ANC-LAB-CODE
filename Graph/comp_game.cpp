// Keywords: playing a computer game.rectangular grid of 2 rows and n columns:

/// explanation: observing the moves, if same column both rows have 1,then no else yes. (tricky not graph)

///tricK: here input is given by string not number and we know string is charecter array.


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s,d;
        cin>>s>>d;
        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && d[i] == '1')
            {
                ans = false;
            }
        }
        cout << (ans ? "YES" : "NO")<<endl;
    }
    return 0;
}
