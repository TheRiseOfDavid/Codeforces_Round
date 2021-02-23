#include <iostream>
#include <bits/stdc++.h>
#define MAXN 1000020
#define LOCAL
using namespace std;
int n, temp;
int a[MAXN];
vector<int> num;
unordered_map<int,int> mp;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]) temp = a[i];
        else num.push_back(a[i-1]);
    }
    num.push_back(a[n-1]);
    //for(int i = 0; i < num.size(); i++) cout << num[i] << ' ';
    //cout << '\n';

    int ans = 0;
    for(int i = 0; i < num.size() ; i++){
        if(mp[num[i]] == 0){
            mp[num[i]] = 1;
            ans++;
        }
        else{
            mp.clear();
            mp[num[i]] = 1;
            mp[num[i-1]] = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
