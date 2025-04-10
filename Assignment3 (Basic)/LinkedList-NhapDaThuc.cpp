#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC& B, const double& heso, const int& somu) {
	DONTHUC* newNodeData = new DONTHUC(heso, somu);
	Node* newNode = new Node(newNodeData);

	if (!B.head) {
		B.head = B.tail = newNode;
		return;
	}

	B.tail->next = newNode;
	B.tail = newNode;
}

void Xuat(DATHUC& B) {
	Node* p = B.head;
	bool haveFirst = false;
	while (p != nullptr) {
		double heso = p->data->heso;
		int somu = p->data->somu;

		// Xuly he so
		// neu co dau + thi khong xuat
		if (!heso) {
			goto lmao;
		}

		if (heso == 1) {
			if (haveFirst && somu) {
				cout << '+';
			}
		}
		else if (heso == -1) {
			cout << '-';
			if (!somu) {
				cout << 1;
			}
		}
		else {
			if (heso > 0 && haveFirst) {
				cout << '+';
			}
			cout << heso;
		}

		// Xuly x^?
		if (somu) {
			cout << 'x';
			if (somu != 1) {
				cout << '^';
				cout << somu;
			}
		}

		haveFirst = true;
		lmao:;
		p = p->next;
	}

	if (!haveFirst) {
		cout << 0;
	}
}

double TinhDaThuc(DATHUC& B, const double& x) {
	Node* p = B.head;
	double ans = 0;

	while (p != nullptr) {
		double heso = p->data->heso;
		int somu = p->data->somu;

		ans += heso * pow(x, somu);

		p = p->next;
	}

	return ans;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
