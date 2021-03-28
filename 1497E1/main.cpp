#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200020
using namespace std;
int t, n, k, num[MAXN];
map<int,int> mp;

int divid(int x){
    int ans = 1;
    for(int i = 2; i*i <= x; i++){
        int cnt = 0;
        while(x % i == 0){
            cnt++;
            x /= i;
        }
        if(cnt % 2 != 0) ans *= i;
    }
    return ans*x; //last prime
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        int ans = 0;
        mp.clear();
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> num[i];
            int d = divid(num[i]);
            //cout << "d is " << d << '\n';
            if(mp.count(d)){
                ans++;
                mp.clear();
            }
            mp[d] = 1;
        }
        cout << ans+1 << '\n';
    }


    return 0;
}
