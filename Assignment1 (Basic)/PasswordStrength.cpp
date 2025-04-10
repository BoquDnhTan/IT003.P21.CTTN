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

const vector<char> specialCharList = {'!', '@', '#', '$', '%', '^', '&', '*', '?', '_', '~'};
const vector<char> invalidCharList = {'.', '\\', '/', ' ', ','};
const int BaseScore = 40;
const int Bonus_Excess = 3;
const int Bonus_Upper = 4;
const int Bonus_Number = 5;
const int Bonus_Symbols = 5;
const int Bonus_Combo[] = {0, 15, 25};
const int Bonus_FlatLower[] = {0, -15};
const int Bonus_FlatNumber[] = {0, -35};
int Number_Execess = 0;
int Number_Upper = 0, Number_Lower = 0;
int Number_Numbers = 0;
int Number_Symbols = 0;
const vector<string> outputList = {"KhongHopLe", "Yeu", "Vua", "Manh", "RatManh"};

bool checkValid(const string& s) {
	if ((int) s.size() < 8) {
		return false;
	}
	for (char h : s) {
		for (char invalidChar : invalidCharList) {
			if (h == invalidChar) {
				return false;
			}
		}
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s);

	if (!checkValid(s)) {
		cout << outputList[0];
		return 0;
	}

	Number_Execess = (int) s.size() - 8;
	for (char h : s) {
		Number_Upper += ('A' <= h && h <= 'Z');
		Number_Lower += ('a' <= h && h <= 'z');
		Number_Numbers += ('0' <= h && h <= '9');
		bool isSymbol = false;
		for (char symbolChar : specialCharList) {
			if (h == symbolChar) {
				isSymbol = true;
				break;
			}
		}
		Number_Symbols += isSymbol;
	}


	int score = BaseScore;
	score += Number_Execess * Bonus_Excess;
	score += Number_Upper * Bonus_Upper;
	score += Number_Numbers * Bonus_Number;
	score += Number_Symbols * Bonus_Symbols;

	int Combo_Type = bool(Number_Upper) + bool(Number_Symbols) + bool(Number_Numbers);
	score += Bonus_Combo[max(0, Combo_Type - 1)];

	score += Bonus_FlatLower[(Number_Lower == (int) s.size())];

	score += Bonus_FlatNumber[(Number_Numbers == (int) s.size())];

	if (score < 50) {
		cout << outputList[1];
	}
	else if (score < 75) {
		cout << outputList[2];
	}
	else if (score < 100) {
		cout << outputList[3];
	}
	else {
		cout << outputList[4];
	}

	return 0;
}

/*


*/