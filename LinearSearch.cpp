#include<bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> a, int n, long long int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			return i;
		}
	}
	return -1;
}

int main(){
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int pos = LinearSearch(a, n, x);
	cout << "Index of the target value: " << pos;
	return 0;
}

