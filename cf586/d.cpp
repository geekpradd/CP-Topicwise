#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin >> n;
	int left_s = 0, right_s = 0;
	int left = 0, right = 0;
	for (int i=0; i<n/2; ++i){
		char inp; cin >> inp;
		if (inp == '?') left++;
		else {
			int val = inp - '0';
			left_s += val;
		}
	}
	for (int i=0; i<n/2; ++i){
		char inp; cin >> inp;
		if (inp == '?') right++;
		else {
			int val = inp - '0';
			right_s += val;
		}
	}

	if ((left + right) % 2){
		cout << "Monocarp" << endl;
	}
	else {
		int val = left_s - right_s;
		if (right_s > left_s){
			swap(left, right); val = -val;
		}
		if (left > right){
			cout << "Monocarp" << endl;
		}
		else if (left == right){
			if (val != 0)
				cout << "Monocarp" << endl;
			else 
				cout << "Bicarp" << endl;
		}
		else if (left < right) {
			int l = (right-left)/2;
			if (val == 9*l){
				cout << "Bicarp" << endl;
			}
			else {
				cout << "Monocarp" << endl;
			}
		}
	}

}
