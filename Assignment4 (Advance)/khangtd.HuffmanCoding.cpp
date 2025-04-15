#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 2e5 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n;
string s;
int cnt[256];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> adj[MAX_N];
int a[MAX_N];
int ans = 0;

void dfs(int u, int h = 0) {
	bool haveChild = false;
	for (int v : adj[u]) {
		haveChild = true;
		dfs(v, h + 1);
	}
	if (!haveChild) {
		ans += a[u] * h;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (char h : s) {
		int x = h;
		cnt[x]++;
	}

	n = 0;
	for (int i = 0; i < 256; i++) {
		if (cnt[i]) {
			n++;
			pq.push({cnt[i], n});
			a[n] = cnt[i];
		}
	}

	if (pq.size() == 1) {
		n++;
		pq.push({0, n});
	}
	while (pq.size() > 1) {
		auto it1 = pq.top();
		pq.pop();
		auto it2 = pq.top();
		pq.pop();
		n++;
		adj[n].pb(it1.se);
		adj[n].pb(it2.se);
		pq.push({it1.fi + it2.fi, n});
	}

	dfs(n);
	cout << ans;

	return 0;
}

/*


*/