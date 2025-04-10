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

int n;
int a[MAX_N];
int b[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}


	////////////////////////
	set<pii> s;
	int ans1 = 0;

	for (int i = 1; i <= n; i++) {
		s.insert({a[i], i});
	}

	for (int i = 1; i <= n; i++) {
		s.erase({a[i], i});

		if (s.empty() || a[i] <= s.begin()->fi) continue;

		pii tmp = *s.begin();
		s.erase(tmp);

		s.insert({a[i], tmp.se});

		swap(a[i], a[tmp.se]);

		ans1++;
	}

	for (int i = 1; i <= n; i++) {
		a[i] = b[i];
	}

	//////////////////////////
	int ans2 = 0;
	s.clear();
	for (int i = 1; i <= n; i++) {
		s.insert({a[i], i});
	}

	for (int i = 1; i <= n; i++) {
		// cerr << "LMAO:\n";
		// for (auto it : s) {
		// 	cout << it.fi << ' ' << it.se << '\n';
		// }

		s.erase({a[i], i});

		if (s.empty() ||a[i] >= (--s.end())->fi) continue;

		pii tmp = *(--s.end());
		s.erase(--s.end());

		// cerr << i << ' ' << a[i] << ' ' << tmp.fi << ' ' << tmp.se << endl;

		s.insert({a[i], tmp.se});

		swap(a[i], a[tmp.se]);

		ans2++;
	}

	cout << min(ans1, ans2);

	return 0;
}

/*


*/