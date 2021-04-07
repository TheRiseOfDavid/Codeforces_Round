#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], fa[N];
vector < int > tot;
bool del[N];
int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue < int > q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			fa[i] = i;
			q.push(i);
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (del[u])	continue;
			int v = (find(u) + 1) % n; //可以保證每次都成功，因為他都把 u 移到了 v 旁邊
			if (v == 0)	v = n;
			if (__gcd(a[u], a[v]) == 1) { 
				q.push(u); 
				int f1 = find(u), f2 = find(v);
				fa[f1] = f2; del[v] = true;
				tot.push_back(v);
			}
		}
		cout << tot.size() << " ";
		for (auto x:tot) 
			cout << x << " ";
		cout << endl;
		tot.clear();
		for (int i = 1; i <= n; i++)	a[i] = 0, del[i] = false;
	}
	return 0;
}