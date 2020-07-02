#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
 
struct node {
	int value, baap,to;
};
struct cus {
	int found, cycle, index;
};
 
 
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int k; cin >> k;
	vector<int> boxes[k];
	vector<int> sums(k);
	map<int, int> origin;
	int total = 0;
	int size = 0;
	int count = 0;
	for (int i=0; i<k; ++i){
		int n; cin >> n; size += n;
		int sum = 0;
		boxes[i].resize(n);
		for (int j=0;j <n; ++j){
			cin >> boxes[i][j];
			total += boxes[i][j];
			sum += boxes[i][j];
			origin[boxes[i][j]] = count;
			count++;
		}
		sums[i] = sum;
	}
	int val = total/k;
	if (k*val != total){
		cout << "No" << endl;
	}
	else {
		vector<node> adj(size);
		int count = 0;
		for (int i=0; i<k; ++i){
			for (int j=0; j<boxes[i].size(); ++j){
				int to;
				int rem = val + boxes[i][j] - sums[i];
				if (origin.count(rem)){
					to = origin[rem];
				}
				else {
					to = -1;
				}
				adj[count] = {boxes[i][j], i, to};
 
				count++;
			}
		}
 
		int cycle = 1;
		vector< vector<node> > cycles;
		vector<int> bitmasks;
		vector<int> inverse(1LL << k, -1);
		vector<cus> visited(size, {0, 0, 0});
		for (int i=0; i<size; ++i){
			// cout << "At " << i << endl;
			if (visited[i].found) continue;
			int cur = i;
			bool got = 1;
			vector<int> path;
			int j = 0;
			int found_i;
			while (true){
				if (cur == -1){
					got = false; break;
				}
				if (!visited[cur].found){
					visited[cur] = {1, cycle, j};
				}
				else if (visited[cur].found && visited[cur].cycle != cycle){
					got = false; break;
				}
				else {
					found_i = visited[cur].index;
					break;
				}
 
				path.pb(cur);
				cur = adj[cur].to;
				j++;
			}
 
			if (got){
				vector<node> current;
				bool okay = 1;
				int mask = 0;
				vector<bool> found(k, false);
				for (int i= found_i; i<j; ++i){
					current.pb(adj[path[i]]);
					if (found[adj[path[i]].baap]){
						okay = 0; break;
					}
					else {
						found[adj[path[i]].baap] = 1;
						mask |= (1LL << adj[path[i]].baap);
					}
				}
				if (okay){
					cycles.pb(current);
					bitmasks.pb(mask);
					inverse[mask] = bitmasks.size() - 1;
				}
			}
			cycle++;
		}
 
		vector<ii> dp(1LL << k, mp(-1, -1));
		dp[0] = mp(1, -1);
		for (int i=1; i< (1LL<<k); ++i){
			int no_set_bits = 0;
			vector<int> positions(k);
			for (int j = 0; j<k; ++j){
				if ((1LL << j) &  i){
					positions[no_set_bits] = j;
					no_set_bits++;
				} 
			}
			
			int ans = -1;
			int first;
			for (int j = 1; j < (1LL << no_set_bits); ++j){
				int copy = i;
				int current = 0;
				for (int l = 0; l < no_set_bits; ++l){
					if ( (1LL << l) & j){
						int ind = positions[l];
						current |= (1LL << ind);
					}
				}
				int rem = copy - current;
				if (inverse[current] != -1){
					if (dp[rem].first != -1){
						ans = rem;
						first = inverse[current];
						break;
					}
				}
			}
 
			if (ans != -1){
				dp[i] = mp(first, ans);
			}
		}
		if (dp[(1LL<<k) - 1].first != -1){
			vector<ii> ans(k, mp(-1, -1));
			int current = (1LL << k) - 1;
			int tot = 0;


			while (current){
				int index = dp[current].first;
				vector<int> t;
				vector<int> z;
				for (node i: cycles[index]){

					ans[adj[i.to].baap] = mp(adj[i.to].value, i.baap + 1);
				}

 				tot += cycles[index].size();
				current = dp[current].second;
			}
		
			cout << "Yes" << endl;
			for (int i=0; i<k; ++i){
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}
		else {
			cout << "No" << endl;
		}
	}
	
	return 0;
 
 
}