#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;
int n;

void get_ans(int p[], int l, int r, vector< vector<int> > &segs){
	if (r == l)
		return;
	if (r == l + 1){
		p[l] = segs[0][0];
		p[r] = segs[0][1];
		return;
	}
	vector<int> counter(n+1, 0);
	vector<int> which(n+1, -1);
	for (int i=0; i<segs.size(); ++i){
		for (int elem: segs[i]){
			counter[elem]++;
			which[elem] = i;
		}
	}
	vector<int> singles;
	for (int i=1; i<=n; ++i){
		if (counter[i]==1)
			singles.pb(i);
	}
	if (singles.size()==1){
		p[r] = singles[0];
		vector< vector<int> > cur;
		vector<int> res;
		for (int i: segs[which[p[r]]]){
			if (i != p[r]) 
				res.pb(i);
		}
		bool extra = 0;
		for (int i=0; i<segs.size(); ++i){
			if (i==which[p[r]]) continue;
			if (segs[i].size() > res.size()){
				int small_ind = 0;
				for (int j=0; j<segs[i].size() && small_ind < res.size(); ++j){
					if (segs[i][j] == res[small_ind])
						small_ind++;
				}
				if (small_ind >= res.size()){
					extra = 1; continue;
				}
			}
			cur.pb(segs[i]);
		}
		if (extra)
			cur.pb(res);
		get_ans(p, l, r-1, cur);
	}
	else {
		vector< vector<int> > cur;
		
		if (segs[which[singles[0]]].size() == segs[which[singles[1]]].size()){
			if (r == l + 2){
				p[r] = singles[0];
				p[l] = singles[1];
			}
			else {
				get_ans(p, l+1, r-1, cur);
				int other_zero = singles[0];
				for (int num: segs[which[singles[0]]])
					other_zero = other_zero ^ num;
				if (other_zero == p[l+1]){
					p[l] = singles[0]; p[r] = singles[1];
				}
				else {
					p[l] = singles[1]; p[r] = singles[0];
				}
				return;
			}

			for (int i=0; i<segs.size(); ++i){
				if (i==which[singles[0]]) continue;
				if (i==which[singles[1]]) continue;
				cur.pb(segs[i]);
			}
		}
		else if (segs[which[singles[0]]].size() > segs[which[singles[1]]].size()){
			p[r] = singles[0];
			p[l] = singles[1];
			vector<int> res;
			for (int i: segs[which[p[r]]]){
				if (i != p[r]) 
					res.pb(i);
			}
			bool extra = 0;
			for (int i=0; i<segs.size(); ++i){
				if (i==which[p[r]]) continue;
				if (segs[i].size() > res.size()){
					int small_ind = 0;
					for (int j=0; j<segs[i].size() && small_ind < res.size(); ++j){
						if (segs[i][j] == res[small_ind])
							small_ind++;
					}
					if (small_ind >= res.size()){
						extra = 1; continue;
					}
				}
				cur.pb(segs[i]);
			}
			if (extra)
				cur.pb(res);
			
		}
		else {
			p[r] = singles[1];
			p[l] = singles[0];
			vector<int> res;
			for (int i: segs[which[p[r]]]){
				if (i != p[r]) 
					res.pb(i);
			}
			bool extra = 0;
			for (int i=0; i<segs.size(); ++i){
				if (i==which[p[r]]) continue;
				if (segs[i].size() > res.size()){
					int small_ind = 0;
					for (int j=0; j<segs[i].size() && small_ind < res.size(); ++j){
						if (segs[i][j] == res[small_ind])
							small_ind++;
					}
					if (small_ind >= res.size()){
						extra = 1; continue;
					}
				}
				cur.pb(segs[i]);
			}
			if (extra)
				cur.pb(res);
		}
		if (r == l + 2){
			int other = p[l];
			for (int num: segs[which[p[l]]])
				other = other ^ num;
			p[l+1] = other;
			return;
		}
		get_ans(p, l+1, r-1, cur);
	}
}

void solve(){
	cin >> n;
	vector< vector<int> > segs(n-1);
	for (int i=0; i<n-1; ++i){
		int ki; cin >> ki;
		vector<int> cur(ki);
		for (int j=0; j<ki; ++j)
			cin >> cur[j];
		segs[i] = cur;
	}
	int p[n];
	for (int i=0; i<n; ++i) p[i] = 0;
	get_ans(p, 0, n-1, segs);
	for (int i=0; i<n; ++i)
		cout << p[i] << " ";
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}