#include <iostream>
#include <bits/stdc++.h>
#define MAXN 1000200
#define int long long
#define LOCAL
using namespace std;
int t, n, k;
int num[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> num[i];
        sort(num, num+n);
        int x1 = num[0], gcd = 0;
        for(int i = 1; i < n; i++) gcd = __gcd(gcd,num[i] - x1);
        if((k - x1) % gcd == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
