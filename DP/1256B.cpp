#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define test int tc; cin>> tc; while(tc--)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){

    optimize();

    test{
        ll n;
        cin >> n;
        ll sum = 0, l = 0, r = 0, x = 0;
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            sum += v[i];
            if (sum > x)
                x = sum, r = i;
            if (sum <= 0)
                sum = 0, l = i;
        }
        l == 0 && r == n ? cout << "YES\n" : cout << "NO\n";
    }
return 0;
}
