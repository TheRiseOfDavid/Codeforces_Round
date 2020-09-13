#include<vector>
#include<iostream>
#define ll long long
#define P pair<int, int>
#define Pll pair<ll, ll>
#define pb push_back
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
struct LiChao_segment_tree{
    inline ll f(ll k, int x, ll b){
        return k*x+b;
    }
    ll k[maxn<<2], b[maxn<<2]; int lz[maxn<<2];
    int N;
    void init(int n){
        N = n; lz[1] = 1; k[1] = b[1] = 0;
    }
    inline void down(int rt){
        if(!lz[rt]) return;
        lz[rt<<1] = lz[rt<<1|1] = 1;
        k[rt<<1] = k[rt<<1|1] = b[rt<<1] = b[rt<<1|1] = 0;
        lz[rt] = 0;//AHHHHHHH!!
        return;
    }
    void update(int rt, int l, int r, ll ck, ll cb){
        if(f(ck, mid, cb) > f(k[rt], mid, b[rt])) swap(k[rt], ck), swap(b[rt], cb);
        if(l == r) return;
        down(rt);
        if(ck > k[rt]) update(rson,ck, cb);//要传的斜率较大，去右边
        else update(lson, ck, cb);//否则去左边
    }
    ll qry(int rt, int l, int r, int x){
        ll ans = f(k[rt], x, b[rt]);
        if(l == r) return ans;
        down(rt);
        if(x <= mid) ans = max(ans, qry(lson, x));
        else ans = max(ans, qry(rson, x));
        return ans;
    }
}T;
vector<int> g[maxn];
int  sz[maxn], ms[maxn], vis[maxn], totsz;
ll a[maxn];
int n, rt;
ll ans = 0;
void get_rt(int u, int fa){
    sz[u] = 1; ms[u] = 0;
    for(int v: g[u]){
        if(v == fa || vis[v]) continue;
        get_rt(v, u);
        sz[u] += sz[v];
        ms[u] = max(ms[u], sz[v]);
    }
    ms[u] = max(ms[u], totsz - sz[u]);
    if(ms[rt] > ms[u]) rt = u;
}
void init()
{
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int u ,v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    totsz = n;
}
void qry(int u, int fa, ll sum, ll xsum, int d){
    int f = 0; d++; sum += a[u]; xsum += sum;
    for(int v: g[u]){
        if(vis[v] || v == fa) continue;
        f = 1;
        qry(v, u, sum, xsum, d);
    }
    if(f) return;
    ans = max(ans, xsum + T.qry(1, 1, T.N, d));
}
void update(int u, int fa, ll sum, ll xsum, int d){
    d++; sum += a[u]; xsum += d*a[u];
    int f = 0;
    for(int v: g[u]){
        if(vis[v] || v == fa) continue;
        f = 1;
        update(v, u, sum, xsum, d);
    }
    if(f) return;
    T.update(1, 1, T.N, sum, xsum);
}
void cal(int u, int cursize){
    T.init(cursize);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(vis[v]) continue;
        qry(v, u, a[u], a[u], 1);
        update(v, u, 0, 0, 0);
    }
    ans = max(ans, a[u] + T.qry(1, 1, T.N, 1));
    T.init(cursize);
    for(int i = g[u].size()-1; i >= 0; --i){
        int v = g[u][i];
        if(vis[v]) continue;
        qry(v, u, a[u], a[u], 1);
        update(v, u, 0, 0, 0);
    }
}
void gao(int u, int cursize)
{
    vis[u] = 1;
    cal(u, cursize);
    for(int v: g[u]){
        if(vis[v]) continue;
        totsz = sz[v] < sz[u] ? sz[v] : cursize - sz[u];
        rt = 0;
        get_rt(v, 0);
        gao(rt, totsz);
    }
}
void sol(){

    rt = 0; ms[rt] = n+1;
    get_rt(1, 0);
    gao(rt, n);
    cout<<ans<<endl;
}
int main()
{
    freopen("in1.txt", "r", stdin);
	init();sol();
}
/*
4
4 2
3 2
4 1
1 3 3 7
*/
