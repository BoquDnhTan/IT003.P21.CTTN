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

int n, m, q;

struct TrieNode {
	int child[26];
};

vector<TrieNode> Trie;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Trie.pb(TrieNode());

	cin >> n >> m >> q;
	vector<string> a(n + 10);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = ' ' + a[i];

		for (int j = 1; j <= m; j++) {
			int p = 0;

			for (int k = 0; k < 10 && j + k <= m; k++) {
				int h = a[i][j + k] - 'a';
				if (!Trie[p].child[h]) {
					Trie[p].child[h] = (int) Trie.size();
					Trie.pb(TrieNode());
				}
				p = Trie[p].child[h];
			}
		}
	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			int p = 0;

			for (int k = 0; k < 10 && i + k <= n; k++) {
				int h = a[i + k][j] - 'a';
				if (!Trie[p].child[h]) {
					Trie[p].child[h] = (int) Trie.size();
					Trie.pb(TrieNode());
				}
				p = Trie[p].child[h];
			}
		}
	}

	while (q--) {
		string s;
		cin >> s;

		bool ok = true;
		int p = 0;
		for (char h_ : s) {
			int h = h_ - 'a';
			if (!Trie[p].child[h]) {
				ok = false;
				break;
			}
			p = Trie[p].child[h];
		}

		cout << ok;
	}

	return 0;
}

/*


*/