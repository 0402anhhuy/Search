#include<bits/stdc++.h>
using namespace std;

int InterpolationSearch(vector<int> a, int n, int x){
	int l = 0, r = n - 1;
	while(l <= r && x >= a[l] && x <= a[r]){
		int m = l + (r - l) * (x - a[l]) / (a[r] - a[l]);
		if(a[m] == x) return m;
		else if(a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int main(){
	int n, x; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	int pos = InterpolationSearch(a, n, x);
	cout << "Index of the target value: " << pos;
	return 0;
}
