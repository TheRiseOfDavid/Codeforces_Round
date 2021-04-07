#include<bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 1e6;
int a[MAXN], fa[MAXN], del[MAXN];
int t, n;
vector<int> record;
deque<int> q;

int find_root(int x){
    return fa[x] == x ? x : fa[x] = find_root(fa[x]);
}

int main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        q.clear();
        record.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            fa[i] = i;
            del[i] = 0;
            q.push_back(i);
        }

        while(!q.empty()){
            int u = q.front(); q.pop_front();
            if(del[u]) continue;
            int v = (find_root(u)+1) % n;
            if(v == 0) v = n;

            if(__gcd(a[u], a[v]) == 1){
                record.push_back(v);
                int fu = find_root(u);
                int fv = find_root(v);
                fa[fu] = fv;
                del[v] = 1;
                q.push_back(u);
            }
        }
        cout << record.size();
        for(auto it: record) cout << ' ' << it;
        cout << '\n';
    }
}
