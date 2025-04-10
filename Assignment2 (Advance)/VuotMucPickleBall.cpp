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
const int MAX_VAL = 200 + 1;

int n, d, ans;
int a[MAX_N];
int cnt[MAX_VAL];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= d; i++) {
		cnt[a[i]]++;
	}

	if (d & 1) {
		int halfD = d;
		halfD >>= 1;
		halfD++;

		for (int i = d + 1; i <= n; i++) {
			if (i - d - 1 > 0) {
				cnt[a[i - d - 1]]--;
			}

			int prevNum = 0;
			for (int j = 0; j <= 200; j++) {
				prevNum += cnt[j];
				if (prevNum >= halfD) {
					ans += (a[i] >= (j << 1));
					break;
				}
			}

			cnt[a[i]]++;
		}

		cout << ans;
	}
	else {
		int halfD = d;
		halfD >>= 1;

		for (int i = d + 1; i <= n; i++) {
			if (i - d - 1 > 0) {
				cnt[a[i - d - 1]]--;
			}

			int prevNum = 0;
			int firstNum = -1;
			int secondNum = -1;

			for (int j = 0; j <= 200; j++) {
				prevNum += cnt[j];
				if (prevNum >= halfD) {
					if (~firstNum) {
						secondNum = j;
						break;
					}
					if (prevNum == halfD) {
						firstNum = j;
					}
					else {
						firstNum = j;
						secondNum = j;
						break;
					}
				}
			}

			ans += (a[i] >= firstNum + secondNum);

			cnt[a[i]]++;
		}

		cout << ans;
	}

	return 0;
}

/*


*/