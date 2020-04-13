#include <bits/stdc++.h>
using namespace std;


pair<int, int> operator*(const pair<int, int> &l, const pair<int, int> &r){
	return make_pair(l.first * r.first, l.second*r.second);
}

int main(){
	long long x; cin >> x;
	cout << x*x << endl;
	return 0;
}

