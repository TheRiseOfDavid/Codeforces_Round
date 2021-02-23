#include<bits/stdc++.h>
#define LOCAL
#define MAXN 200020
#define int long long
#define INF 0x3f3f3f
using namespace std;
int t, n, num[MAXN];
int pre[MAXN], suf[MAXN];

int solve(){

    for(int i = 1; i < n; i++){
        if(suf[i+1] == pre[i])
            return 1;
        int x = num[i+1] - pre[i-1], y = num[i] - suf[i+2] ;
        if(x >= 0 && y >= 0 && x == y)
            return 1;
    }
    return 0;
}

int32_t main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> num[i];
        suf[n+1] = 0;
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            if(num[i] - pre[i-1] < 0)
                pre[i] = INF;
            else
                pre[i] = num[i] - pre[i-1];
        }
        for(int i = n; i > 0; i--){
            if(num[i] - suf[i+1] < 0)
                suf[i] = INF + MAXN;
            else
                suf[i] = num[i] - suf[i+1];
        }
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
