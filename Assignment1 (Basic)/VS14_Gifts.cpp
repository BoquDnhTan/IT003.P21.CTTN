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

int n, x;
int a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int ans = 0;
	for (int i = 2; i <= n && a[i] <= x; i++) {
		int low = 1, high = i - 1;
		int rest = x - a[i];
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (a[mid] <= rest) {
				maximize(ans, a[mid] + a[i]);
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}

	cout << ans;

	return 0;
}

/*


*/