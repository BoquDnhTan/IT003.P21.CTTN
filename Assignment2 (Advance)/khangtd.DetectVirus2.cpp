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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;

	cin >> s >> t;

	vector<int> ansList;

	s = t + '#' + s;
	int n = (int) s.size();

	// cout << s << '\n';

	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    int m = (int) t.size();
    for (int i = 0; i < n; i++) {
    	if (pi[i] == m) {
    		ansList.pb(i - 2 * m + 1);
    	}
    }

    if (ansList.empty()) {
    	cout << "NO";
    	return 0;
    }
    cout << "YES\n";
    for (auto it : ansList) {
    	cout << it << ' ';
    }

	return 0;
}

/*


*/