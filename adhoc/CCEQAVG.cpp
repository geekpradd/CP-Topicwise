#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int overshoot_count = n%k;
		int normal_count = k - n%k;
		int a[n];
		bool pos = 1;
		for (int i=0; i<n; ++i) cin >> a[i];
		map<int, int> itr;
		for (int i=0; i<n; ++i){
			if (itr.count(a[i])) itr[a[i]]++;
			else
				itr[a[i]] = 1;
		}
		int rep_size = n/k;
		int a_count = 0, b_count = 0;
		vector<int> extras; vector<int> normals;
		for (auto iter = itr.begin(); iter != itr.end(); ++iter){
			int freq = iter->second;
			cout << "for val " << iter->first << " freq " << freq << endl;
			int a = freq % rep_size;
			int b = (freq/rep_size) - a;
			cout << "a is " << a << endl;
			cout << "b is " << b << endl;
			if (b<0) pos = 0;
			a_count+=a; b_count+=b;
			for (int i=0; i<a; ++i) extras.push_back(iter->first);
			for (int i=0; i<b; ++i) normals.push_back(iter->first);
		}
		if (b_count != normal_count || a_count != overshoot_count)
			pos = 0;
		if (pos){
			cout << "YES" << endl;
			for (int i=0; i<rep_size; ++i){
				for (int j=0; j<overshoot_count; ++j)
					cout << extras[j] << " ";
				for (int j=0; j<normal_count; ++j)
					cout << normals[j] << " ";
			}
			for (int j=0; j<overshoot_count; ++j)
				cout << extras[j] << " ";
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

