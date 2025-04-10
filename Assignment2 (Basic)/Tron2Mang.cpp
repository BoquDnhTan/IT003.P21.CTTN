/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//###INSERT CODE HERE -
void merge(int* &a, const int& n, int* &b, const int& m, int* &c) {
    int i = 0, j = 0;
    int d = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[d++] = a[i++];
        }
        else {
            c[d++] = b[j++];
        }
    }
    while (i < n) {
        c[d++] = a[i++];
    }
    while (j < m) {
        c[d++] = b[j++];
    }
}


int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
