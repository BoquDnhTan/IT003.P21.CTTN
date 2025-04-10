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

const int MAX_N = 1e5 + 5;

int n, k;
int a[MAX_N];
int cnt[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numCases = 0;
	cin >> numCases;
	for (int testCase = 1; testCase <= numCases; testCase++) {
		cin >> n >> k;
		vector<int> ns;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ns.pb(a[i]);
		}

		sort(all(ns));
		ns.erase(unique(all(ns)), ns.end());

		if ((int) ns.size() > 2 * k) {
			cout << "NO\n";
			continue;
		}

		if ((int) ns.size() == 2 * k) {
			cout << "YES\n";
			continue;
		}

		for (int &x : ns) cnt[x] = 0;
		for (int i = 1; i <= n; i++) {
			cnt[a[i]]++;
		}
		int numDiff = 0;
		for (int &x : ns) numDiff += (cnt[x] > 1);

		cout << ((int) ns.size() + numDiff >= 2 * k ? "YES" : "NO") << '\n';
	}

	return 0;
}

/*


*/