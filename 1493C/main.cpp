#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int T, k, n;
int cnt[30], sum[MAXN][30], now;
string s;

int check(int x){
    for(int i = s[x]-'a'+1; i < 26; i++){
        memset(cnt, 0, sizeof(cnt));
        int remain = n-x-1;
        for(int j = 0; j < 26; j++){
            now = sum[x][j];
            if(j == s[x]-'a') now--;
            else if(i == j) now++;

            remain -= (k-now%k)%k;
            cnt[j] += (k-now%k)%k;
            if(remain < 0) break;
        }
        if(remain < 0) continue;

        cnt[0] += remain;
        return i;
    }
    return 0;
}

string solve(){
    if(s.length() % k != 0) return "-1";

    for(int i = 0; i < 26; i++) sum[0][i] = 0;
    for(int i = 0; i < n; i++){
        sum[i][s[i] - 'a'] += 1;
        for(int j = 0; j < 26; j++) sum[i+1][j] = sum[i][j];
    }

    int flag = 1;
    for(int i = 0; i < 26; i++){
        if(sum[n-1][i] % k != 0){
            flag = 0;
            break;
        }
    }
    if(flag == 1) return s;

    string ans = "";
    for(int i = n-1; i >= 0; i--){
        flag = check(i);
        if(flag){
            ans = s.substr(0, i) + (char) (flag+'a');
            for(int i = 0; i < 26; i++) ans += string(cnt[i], i+'a');
            return ans;
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> T;
    while(T--){
        cin >> n >> k >> s;
        cout << solve() << '\n';
    }
    return 0;
}
