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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) {
			cin >> x;
		}

		int ans = a[n - 1] - a[0];
		if (n >= 4) {
			ans += a[n - 2] - a[1];
		}

		cout << ans << '\n';
	}

	return 0;
}

/*


*/