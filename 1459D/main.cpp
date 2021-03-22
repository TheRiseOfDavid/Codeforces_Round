#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 120
using namespace std;
int dp[MAXN][MAXN*MAXN];
int a[MAXN], b[MAXN];
int all, sum, n;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i] >> a[i];
        sum += a[i];
        all += b[i];
    }

    //for(int i = 0; i < MAXN; i++){
    //    for(int j = 0; j < MAXN*MAXN; j++) dp[i][j] = -MAXN * MAXN;
    //}
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            for(int k = all; k >= b[i]; k--) dp[j][k] = max(dp[j][k], dp[j-1][k-b[i]]+a[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        double ans = 0;
        for(int j = 0; j <= all; j++){
            ans = max(ans, min( (sum+dp[i][j]) / 2.0, 1.0 * j));
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';

        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}
