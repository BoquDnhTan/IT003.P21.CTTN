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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	cin >> k;
	
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			ans.pb(i);
		}
	}

	cout << (int) ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ' << x + 1 << '\n';
	}

	return 0;
}

/*


*/