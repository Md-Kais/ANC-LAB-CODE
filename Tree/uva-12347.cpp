#include <bits/stdc++.h>
using namespace std;

void postOrder(int pre[], int n, int minval, int maxval, int &preIndex)
{

    if (preIndex == n)
        return;

    if (pre[preIndex] < minval || pre[preIndex] > maxval)
    {
        return;
    }

    int val = pre[preIndex];
    preIndex++;
    postOrder(pre, n, minval, val, preIndex);
    postOrder(pre, n, val, maxval, preIndex);
    cout << val << endl;
}

int main()
{
    int pre[123456];

    int val;
    scanf("%d", &val);
    
    int n=0;
    pre[n] = val;
    while (scanf("%d", &val) == 1)
    {
       
        n++;
        pre[n] = val;
    }

    // for(auto e: pre){
    //     cout<<e<<endl;
    // }

    int preIndex = 0;

    postOrder(pre, n+1, INT_MIN, INT_MAX, preIndex);

    return 0;
}
