#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> a, int l, int m, int r){
	int len_left = m - l + 1;
	int len_right = r - m;
	vector<int> a_left(len_left);
	vector<int> a_right(len_right);
	for(int i = 0; i < len_left; i++){
		a_left[i] = a[l + i];
	}
	for(int i = 0; i < len_right; i++){
		a_right[i] = a[m + 1 + i];
	}
	int i = 0, j = 0;
	while(i < len_left && j < len_right){
		if(a_left[i] <= a_right[j]){
			a[l++] = a_left[i++];
		}
		else{
			a[l++] = a_right[j++];
		}
	}
	while(i < len_left){
		a[l++] = a_left[i++];
	}
	while(j < len_right){
		a[l++] = a_right[j++];
	}
}

void mergeSort(vector<int> &a, int l, int r){
	if(l >= r) return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

int BinarySearch(vector<int> a, int l, int r, int x){
	if(l > r) return -1;
	else{
		int m = (l + r) / 2;
		if(x < a[m]) return BinarySearch(a, l, m - 1, x);
		else if(x > a[m]) return BinarySearch(a, m + 1, r, x);
		else return m;
	}	
}

int main(){
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	mergeSort(a, 0, n);
	int pos = BinarySearch(a, 0, n, x);
	cout << "Index of the target value: " << pos;
	return 0;
}
