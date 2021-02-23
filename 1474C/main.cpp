#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1000020
using namespace std;
int t, n, x, num[MAXN], a[MAXN];
vector<pair<int,int> > record;

void solve(){
    sort(a,a+2*n);
    for(int i = 0; i < 2*n-1; i++){
        record.clear();
        memset(num, 0, sizeof(num));
        for(int j = 0; j <= 2*n-1; j++)
            num[a[j]]++;
        x = a[i] + a[2*n-1];
        //cout << "x is " << x << '\n';
        int cnt = n;
        while(cnt){
            int pos = 2*n-1;
            while(pos > 0 && num[a[pos]] == 0)
                pos--;
            num[a[pos]]--; num[x-a[pos]]--;
            if(num[a[pos]] < 0 || num[x-a[pos]] < 0)
                break;
            record.push_back({a[pos], x-a[pos]});
            //cout << a[pos] << ' ' << x-a[pos] << '\n';
            x = max(a[pos], x-a[pos]);
            cnt--;
        }
        if(cnt == 0 ){
            cout << "YES\n";
            cout << record[0].first + record[0].second << '\n';
            for(auto it: record)
                cout << it.first << ' ' << it.second << '\n' ;
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 2*n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
