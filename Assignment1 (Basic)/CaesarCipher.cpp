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

string s;
int k;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k;
	k %= 26;	

	getline(cin, s);
	getline(cin, s);

	for (char h : s) {
		if ('A' <= h && h <= 'Z') {
			cout << char('A' + ((int(h) - 'A' + k)) % 26);
		}
		else {
			cout << h;
		}
	}

	return 0;
}

/*


*/