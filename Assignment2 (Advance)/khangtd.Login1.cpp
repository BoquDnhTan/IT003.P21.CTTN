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

map<string, string> psw;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		string tk, mk;
		cin >> tk >> mk;
		psw[tk] = mk;
	}

	while (q--) {
		string s;
		cin >> s;

		string pass = psw[s];
		if (pass.size() == 0) {
			cout << "Chua Dang Ky!\n";
			continue;
		}
		cout << pass << '\n';
	}

	return 0;
}

/*


*/