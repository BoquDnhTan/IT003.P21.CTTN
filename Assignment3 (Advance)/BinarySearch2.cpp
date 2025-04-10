#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

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

int n, q;
pii a[MAX_N];

template<typename T>
void sapxep(T* a, int l, int r) {
	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	sapxep(a, l, mid);
	sapxep(a, mid + 1, r);

	vector<T> leftList(a + l, a + mid + 1), rightList(a + mid + 1, a + r + 1);

	merge(all(leftList), all(rightList), a + l);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}

	sapxep(a, 1, n);

	while (q--) {
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;

		int low = 1, high = n;
		int pos = -1;
		if (x == 1) {
			while (low <= high) {
				int mid = (low + high) >> 1;
				if (a[mid].fi >= y) {
					pos = mid;
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
		else {
			while (low <= high) {
				int mid = (low + high) >> 1;
				if (a[mid].fi <= y) {
					pos = mid;
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}
		}

		if (~pos) {
			cout << (a[pos].fi == y ? a[pos].se : -1);
		}
		else {
			cout << -1;
		}
		cout << '\n';
	}

	return 0;
}

/*


*/