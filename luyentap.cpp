#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

int main() {
	int n,x; cin >>n >>x;
	int a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	int *it = lower_bound(a, a +n ,x);
	//cout << *it << endl;
	for(int x:a[n])	
		cout << x << " ";
	return 0;
}

