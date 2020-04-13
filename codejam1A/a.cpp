#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool comp(string &l, string &r){
	return l.size() < r.size();
}
signed main(){
	int t; cin >> t;
	for (int l=1; l<=t; ++l){
		int n; cin >> n;
		string v[n];
		for (int i=0; i<n; ++i)
			cin >> v[i];
		string pref[n], suff[n];
		string tot = "";
		for (int i=0; i<n; ++i){
			int j=0;
			for (; j<v[i].size(); ++j){
				if (v[i][j]=='*')
					break;
			}
			pref[i] = v[i].substr(0, j);
			int k = v[i].size()-1;
			for (; k>=0; --k){
				if (v[i][k]=='*')
					break;
			}
			suff[i] = v[i].substr(k+1, v[i].size()-k-1);

			string fin = "";
			for (int l=j+1; l<k;++l){
				if (v[i][l]=='*')
					continue;
				fin += v[i][l];
			}
			tot += fin;
		}
		sort(pref, pref+n, comp);
		sort(suff, suff+n, comp);
		bool poss = 1;
		string l_mas = pref[0];
		string r_mas = suff[0];
		for (int i=1; i<n; ++i){
			for (int j=0; j<min(pref[i].size(), l_mas.size()); ++j){
				if (pref[i][j]!=l_mas[j]){
					poss = 0; break;
				}
			}
			l_mas = pref[i];
		}
		for (int i=1; i<n; ++i){
			for (int j=0; j<min(suff[i].size(), r_mas.size()); ++j){
				if (suff[i][suff[i].size()-1-j]!=r_mas[r_mas.size()-1-j]){
					poss = 0; break;
				}
			}
			r_mas = suff[i];
		}
		string net = l_mas + tot + r_mas;
		if (!poss)
			net = "*";
		cout << "Case #" << l << ": " << net << endl;
	}
}