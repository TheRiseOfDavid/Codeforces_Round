#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 7;
int pre[maxn],suf[maxn],a[maxn];
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        int n;scanf("%d",&n);
        for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
        suf[n + 1] = 0;
        for(int i = 1;i <= n;i++) {
            if(a[i] >= pre[i - 1]) {
                pre[i] = a[i] - pre[i - 1];
            } else {
                pre[i] = INF;
            }
        }
        for(int i = n;i >= 1;i--) {
            if(a[i] >= suf[i + 1]) { //只要一次沒有，全部都是會是無限大
                suf[i] = a[i] - suf[i + 1];
            } else {
                suf[i] = INF + 1e6;
            } 
        }
        int flag = 0;
        for(int i = 1;i < n;i++) {
            if(pre[i] == suf[i + 1]) {
                flag = 1;break;
            } else { //i和i+1交换
                int x = a[i + 1],y = a[i];
                if(x >= pre[i - 1] && y >= suf[i + 2]) {
                    x -= pre[i - 1];y -= suf[i + 2];
                    if(x == y) {
                        flag = 1;break;
                    }
                }
            }
        }
        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}