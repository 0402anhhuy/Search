#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> a, int l, int r, int x){
	if(l > r) return -1;
	else{
		int m = (l + r) / 2;
		if(x < a[m]) return BinarySearch(a, l, m - 1, x);
		else if(x > a[m]) return BinarySearch(a, m + 1, r, x);
		else return m;
	}
}

void Xuat(vector<int> a, int l, int r){
	for(int i = l; i <= r; i++) cout << a[i] << " ";
}

bool PreSum(vector<int> a, int x){
	int sz = a.size();
	vector<int> b(sz);
	b[0] = a[0];
	for(int i = 1; i < sz; i++){
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 0; i < sz; i++){
		if(b[i] == x){
			Xuat(a, 0, i);
			return true;
		}
		if(b[i] > x){
			int l = BinarySearch(b, 0, sz, b[i] - x);
			if(l != -1){
				Xuat(a, l + 1, i);
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, s; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> s;
	bool k = PreSum(a, s);
	if(!k) cout << -1;
	return 0;
}
