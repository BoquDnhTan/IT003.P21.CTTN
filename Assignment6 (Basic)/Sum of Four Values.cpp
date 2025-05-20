#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pill pair<int, ll>
#define plli pair<ll, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
 
const int MAX_N = 1e3 + 5;
const ll mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;
 
int n;
ll x;
ll a[MAX_N];
map<ll, pair<int, int>> m;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			ll need = x - a[i] - a[j];
			if (m.count(need)) {
				if (m[need].first != j && m[need].second != j) {
					cout << i << " " << j << " " << m[need].first << " " << m[need].second;
					return 0;
				}
			}
		}
 
		for (int j = 1; j < i; j++) {
			m[a[i] + a[j]] = {i, j};
		}
	}
 
	cout << "IMPOSSIBLE";
 
	return 0;
}
