#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int in[MAXN], de[MAXN];
int n, num[MAXN], maxn = 0;
vector<int> record[MAXN];

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        in[i] = num[i] > num[i-1] ? in[i-1]+1 : 1;
        if(maxn <= in[i]){
            maxn = in[i];
            record[in[i]].push_back(i);
        }
    }

    de[n] = 1;
    for(int i = n-1; i >= 1; i--){
        de[i] = num[i] > num[i+1] ? de[i+1]+1 : 1;
        if(maxn <= de[i]) record[de[i]].push_back(i);
    }

    int ans = 0;
    if(record[maxn].size() <= 2 && maxn % 2 != 0){
        for(auto it: record[maxn]){
            if(de[it] == in[it]) ans = 1;
        }
    }
    cout << ans;

    /*
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << in[i] << ' ';
        cout << '\n';
    for(int i = 1; i <= n; i++) cout << de[i] << ' ';
        cout << '\n';
    cout << "maxn = " << maxn << '\n';
    /*/

    return 0;
}
