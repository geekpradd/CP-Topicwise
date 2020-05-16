#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	int out[n+1], in[n+1], a[n+1];
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		out[i] = a[i];
		in[a[i]] = i;
	}
	int steps = 0;
	vector< vector<int> >  cycles;
	vector<int> cycle(n+1, -1);
	int even = 0;
	vector<int> even_indexes;
	for (int i=1; i<=n; ++i){
		if (cycle[i] != -1) continue;
		int j = cycles.size();
		cycle[i] = j;
		int to = out[i]; 
		int len = 1;
		vector<int> cur; 
		cur.push_back(i);

		while (to != i){
			len++;
			cycle[to] = j;
			cur.push_back(to);
			to = out[to];
		}
		cycles.push_back(cur);
		if (len%2 == 0){
			even++;
			even_indexes.push_back(j);
		}
	}	
	if (even%2){
		cout << -1 << endl;
		return;
	}
	int count = 0;
	vector< vector<int> > ops;
	for (int i=0; i<even_indexes.size(); i+=2){
		int j = even_indexes[i];
		int k = even_indexes[i+1];
		int a = in[cycles[j][0]];
		int b = in[cycles[k][0]];
		vector<int> op;
		int c = in[cycles[k][1]];
		op.push_back(c); op.push_back(b);
		
		op.push_back(a);

		out[a]= cycles[k][0];
		out[b] = cycles[k][1];
		out[c] = cycles[j][0];
		in[cycles[k][0]] = a;
		in[cycles[k][1]] = b;
		in[cycles[j][0]] = c;

		ops.push_back(op);
		count++;
	}

	vector<int> visited(n+1, 0);
	for (int i=1; i<=n; ++i){
		if (visited[i]) continue;
		vector<int> cur;
		cur.push_back(i);
		int to = out[i];
		visited[i] = 1;
		while (to != i){
			cur.push_back(to);
			visited[to] = 1;
			to = out[to];
		}

		for (int j=0; j<cur.size(); j+=2){
			if (j+1 == cur.size()) break;
			int a = cur[j], b = cur[j+1], c = cur[j+2];
			int ind_a = in[a], ind_b = in[b], ind_c = in[c];
			out[in[a]] = c; in[c] = in[a];
			out[a] = a; in[a] = a;
			out[b] = b; in[b] = b;
			vector<int> op = {ind_a, ind_b, ind_c};
			ops.push_back(op);
			count++;
		}
	}

	if (count>k){
		cout << -1 << endl;
		return;
	}

	cout << count << endl;
	for (int i=0; i<ops.size(); ++i){
		cout << ops[i][0] << " " << ops[i][1] << " " << ops[i][2] << endl;
	}

}

signed main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
}