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

const int MAX_N = 1e6 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n;
int a[MAX_N];
int ans;
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	v.pb(a[1]);
	for (int i = 2; i <= n; i++) {
		int low = 0, high = v.size() - 1;
		int pos = 0;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (v[mid] > a[i]) {
				pos = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		ans += v.size() - pos;
		while (!v.empty() && a[i] > v.back()) {
			v.pop_back();
		}
		v.pb(a[i]);
	}

	cout << ans;

	return 0;
}

/*
2 4 1 2 2 5 1 
0 1 1 2 2 3 1

*/