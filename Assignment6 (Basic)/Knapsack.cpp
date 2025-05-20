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

const int MAX_N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;

int n, w;
int dp[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = w; j >= a; j--) {
            maximize(dp[j], dp[j - a] + b);
        }
    }

    cout << *max_element(dp, dp + w + 1) << '\n';

    return 0;
}

/*


Tuesday, 13 May 2025
13:11:56
*/