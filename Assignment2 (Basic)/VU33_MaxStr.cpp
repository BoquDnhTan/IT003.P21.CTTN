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

int cnt[10];
string s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	for (char &h : s) cnt[h - '0']++;

	int sum = 0;
	for (int i = 1; i < 10; i++) {
		(sum += 1ll * (i % 3) * cnt[i] % 3) %= 3;
	}

	if (sum) {
		for (int i = 1; i < 10; i++) {
			if (cnt[i] && (i % 3) == sum) {
				cnt[i]--;
				sum = 0;
				break;
			}
		}
	}

	if (sum == 2) {
		sum = 2;
		for (int i = 1; i < 10 && sum; i++) {
			if (i % 3 == 1) {
				int tmp = min(2, cnt[i]);
				sum -= tmp;
				cnt[i] -= tmp;
			}
		}
	}
	if (sum == 1) {
		sum = 2;
		for (int i = 1; i < 10 && sum; i++) {
			if (i % 3 == 2) {
				int tmp = min(2, cnt[i]);
				sum -= tmp;
				cnt[i] -= tmp;
			}
		}
	}

	for (int i = 9; ~i; i--) {
		while (cnt[i] --> 0) {
			cout << i;
		}
	}

	return 0;
}

/*


*/