#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 0x3f3f3f
using namespace std;
string s, t;
int n, m, pre = -1, nxt = MAXN, num, ans;
int p[MAXN];
vector<int> vec[30];

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n >> m;
    cin >> s >> t;

    for(int i = 0; i < n; i++){
        num = s[i] - 'a';
        vec[num].push_back(i);
    }

    for(int i = 0; i < m; i++){
        num = t[i] - 'a';
        p[i] = *upper_bound(vec[num].begin(), vec[num].end(), pre);
        //cout << "pre p[i] " << i << ' ' << p[i] << '\n';
        pre = p[i];
    }
    nxt = n;
    for(int i = m-1; i > 0; i--){
        num = t[i] - 'a';
        p[i] = *--lower_bound(vec[num].begin(), vec[num].end(), nxt);
        nxt = p[i];
        //cout << "nxt p[i] " << i << ' ' << p[i] << '\n';
        ans = max(ans, p[i] - p[i-1]);
    }
    cout << ans << '\n';
    return 0;
}
