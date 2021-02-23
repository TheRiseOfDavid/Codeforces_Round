#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1e10
#define int long long
using namespace std;
int x, y, n, ans;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    while(n--){
        cin >> x >> y;
        ans = 0;
        for(int i = 1; i*i < x; i++) ans += max(0ll, min(x/i-1, y) - i);
        cout << ans << "\n";
    }
    return 0;
}
