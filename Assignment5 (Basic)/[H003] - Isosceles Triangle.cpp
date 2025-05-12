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

const int MAX_N = 2e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    map<int, int> cnt;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    auto j = cnt.begin();
    int sum = 0;
    int ans = 0;
    for (auto &it : cnt) {
        while (j != cnt.end() && j->fi < 2 * it.fi) {
            sum += j->se;
            j++;
        }
        sum -= it.se;
        ans += sum * (it.se - 1) * (it.se) / 2;
        sum += it.se;
        ans += it.se * (it.se - 1) * (it.se - 2) / 6;
    }

    cout << ans;

    return 0;
}

/*

C(3, n) = n! / (3! * (n - 3)!)
= n * (n - 1) * (n - 2) / 6

Monday, 12 May 2025
13:20:16
*/