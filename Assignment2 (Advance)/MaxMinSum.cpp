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

const int MAX_N = 1e5 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n, k;
int a[MAX_N];
int fact[MAX_N];
int iFact[MAX_N];

int fastPow(int a, int k) {
	int res = 1;
	while (k) {
		if (k & 1) {
			res = 1ll * res * a % mod;
		}
		a = 1ll * a * a % mod;
		k >>= 1;
	}
	return res;
}

void add(int &a, const int &b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int C(int k, int n) {
	if (k > n) return 0;
	return 1ll * (1ll * fact[n] * iFact[k] % mod) * iFact[n - k] % mod;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
	}

	iFact[n] = fastPow(fact[n], mod - 2);
	for (int i = n - 1; ~i; i--) {
		iFact[i] = 1ll * iFact[i + 1] * (i + 1) % mod;
	}

	sort(a + 1, a + n + 1);

	int res = 0;
	for (int i = 1; i <= n; i++) {
		(a[i] += mod) %= mod;
		add(res, 1ll * a[i] * C(k - 1, i - 1) % mod);
		add(res, 1ll * (mod - a[i]) * C(k - 1, n - i) % mod);
	}

	cout << res;

	return 0;
}

/*


*/