#include <bits/stdc++.h>
#pragma gcc optimise('O3')
#define int long long
#define MOD 1000000007
#define ii pair<int, int>
using namespace std;
vector<int> tin; 
vector<int> tout;
vector< vector<int> > adj;
vector< vector<int> > up;
vector< vector<ii> > pfac;
vector< vector<ii> > selffac;
vector< int > mo_vals;
vector< int > dfs_order;
vector<int> memo(1000001, -1);
int timer;
int cap;
int block;

struct query {
	int l, r, lca, i;
};
int power_m(int base, int exp){
	if (exp==0)
		return 1;
	int res = power_m(base, exp/2);
	res = (res*res)%MOD;
	if (exp%2)
		return (res*base)%MOD;
	return res;
}
int inverse(int n){
	if (memo[n]!=-1)
		return memo[n];
	memo[n] = power_m(n, MOD-2);
	return memo[n];
}

vector<ii> operator+(vector<ii> &l, vector<ii>&r){
	vector<ii> final;
	int cur = -1;
	int l_i = 0, r_i = 0;
	while (l_i < l.size() || r_i < r.size()){
		if (r_i == r.size()){
			if (cur == l[l_i].first)
				final[final.size()-1].second += l[l_i].second;
			else
				final.push_back(l[l_i]);
			l_i++;
		}
		else if (l_i == l.size()){
			if (cur == r[r_i].first)
				final[final.size()-1].second += r[r_i].second;
			else
				final.push_back(r[r_i]);
			r_i++;
		}
		else if (l[l_i].first < r[r_i].first){
			if (cur == l[l_i].first)
				final[final.size()-1].second += l[l_i].second;
			else
				final.push_back(l[l_i]);
			l_i++;
		}
		else {
			if (cur == r[r_i].first)
				final[final.size()-1].second += r[r_i].second;
			else
				final.push_back(r[r_i]);
			r_i++;
		}
		cur = final[final.size()-1].first;
	}
	return final;
}

vector<ii> diff(int low, int upper){
	vector<ii> first = pfac[low];
	if (upper != 1){
		int first_i = 0;
		for (ii i: pfac[up[upper][0]]){
			while (first[first_i].first != i.first){
				first_i++;
			}
			first[first_i].second -= i.second;
		}
	}
	return first;
}
void dfs(int cur, int parent){
	up[cur][0] = parent;
	tin[cur] = ++timer;
	dfs_order[timer] = cur;

	for (int i=1; i<=cap; ++i){
		up[cur][i] = up[up[cur][i-1]][i-1];
	}
	if (cur == parent)
		pfac[cur] = selffac[cur];
	else
		pfac[cur] = selffac[cur] + pfac[parent];

	for (int to: adj[cur]){
		if (to != parent)
			dfs(to, cur);
	}

	tout[cur] = ++timer;
	dfs_order[timer] = cur;
}
bool is_ancestor(int a, int b){
	return  (tin[a]<=tin[b] && tout[a]>=tout[b]);
}

bool comp(query &l, query &r){
	if (l.l/block == r.l/block)
		return l.r < r.r;
	return l.l/block < r.l/block;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		adj.clear();
		tin.clear(); tout.clear(); pfac.clear(); selffac.clear(); up.clear(); mo_vals.clear(); dfs_order.clear();
		adj.resize(n+1); tin.resize(n+1); tout.resize(n+1); mo_vals.resize(n+1); dfs_order.resize(2*n+1);
		cap = (log2(n));

		up.assign(n+1, vector<int>(cap+1));
		pfac.resize(n+1); selffac.resize(n+1);

		for (int i=0; i<n-1; ++i){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		timer = 0;
		int vals[n+1]; 
		for (int i=1; i<=n; ++i){
			cin >> vals[i];
			int v = vals[i];
			int so_far = -1;
			mo_vals[i] = 0;
			for (int fac=2; fac*fac<=v; ++fac){
				if (v%fac==0){
					if (fac == so_far)
						selffac[i][selffac[i].size()-1].second++;
					else{
						selffac[i].push_back(make_pair(fac, 1)); so_far = fac;
					}
					v = v/fac;
					fac--; 
				}
			}
			if (v == so_far)
				selffac[i][selffac[i].size()-1].second++;
			else if(v != 1){
				if (v < 1000)
					selffac[i].push_back(make_pair(v, 1));
				else
					mo_vals[i] = v;
			}
		} 
		dfs(1, 1);
		// for (int i=1; i<=2*n; ++i){
		// 	cout << "DFS[" << i << "] = " << dfs_order[i] << endl;
		// }
		int q; cin >> q;
		long long ansv[q];
		query queries[q];
		for (int i=0; i<q; ++i){
			int u, v; cin >> u >> v;
			int u_org = u, v_org = v;
			int lca, sub;
			vector<ii> fin;
			query qq; qq.i = i;
			if (is_ancestor(u, v)) {
				fin = diff(v, u); qq.l = tin[u]; qq.r = tin[v]; qq.lca = 0;
			}
			else if (is_ancestor(v, u)){
				fin = diff(u, v); qq.l = tin[v]; qq.r = tin[u]; qq.lca = 0;
			} 
			else {
				for (int j=cap; j>=0; --j){
					if (!is_ancestor(up[u][j], v)) u = up[u][j];
				}
				sub = u;
				lca = up[u][0];
				vector<ii> a = diff(v, lca); vector<ii> b = diff(u_org, sub);
				fin = a + b;
				if (tin[u_org]<tin[v]){
					qq.l = tout[u_org]; qq.r = tin[v]; qq.lca = lca;
				}
				else{
					qq.l = tout[v]; qq.r = tin[u_org]; qq.lca = lca;
				}
			}
			long long ans = 1;

			for (ii i: fin){
				long long cur = (i.second + 1)%MOD;
				ans = (ans*cur)%MOD;
			}
			ansv[i] = ans;
			queries[i] = qq;
		}

		block = sqrt(n);
		sort(queries, queries+q, comp);
		int l = 0, r = 0; // these are auxillary
		vector<int> indices(n+1, 0);
		vector<int> primes(1000001, 0);

		int cur_ans = 1;
		int t_l = queries[0].l, t_r = queries[0].r; int i=0;
		while (i<q){
			// cout << "INITIAL " << l << " " << r << endl;
			// cout << "NEED TO " << t_l << " " << t_r << endl;
			while (r < t_r){
				r++; int index = dfs_order[r];
				// cout << "R now " << r << endl;
				// cout << "cur_ans " << cur_ans << endl;

				if (indices[index] != 0){
					// cout << "INDEX already there" << endl;
					indices[index]++;

					if (mo_vals[index] != 0){
						// cout << "PRIME found " << mo_vals[index] << endl;
						int v = primes[mo_vals[index]];
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]--;
						// cout << "NOW COUNT IS " << primes[mo_vals[index]] << endl;
						cur_ans = (cur_ans*(v))%MOD;
					}
				}
				else {
					indices[index] = 1;
					if (mo_vals[index]==0){

					}
					else if (primes[mo_vals[index]]!=0){
						// cout << "EXISTING prime " << endl;
						int v = primes[mo_vals[index]];
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]++;
						cur_ans = (cur_ans*(v+2))%MOD;
					}
					else {
						// cout << "PRIME found" << endl;
						primes[mo_vals[index]] = 1;
						cur_ans = (cur_ans*2)%MOD;
					}
				}
			}
			while (r > t_r){
				int index = dfs_order[r];
				if (mo_vals[index] != 0){
					int coun = indices[index];
					int v = primes[mo_vals[index]];
					if (coun==2){
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]++;
						cur_ans = (cur_ans*(v+2))%MOD;
					}
					else {
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]--;
						cur_ans = (cur_ans*(v))%MOD;
					}
				}
				indices[index]--;
				r--;
			}
			// cout << "cur_ans is " << cur_ans << endl;
			while (l < t_l){
				if (l==0){
					l++; continue;
				}
				// cout << "L now is " << l << endl;
				// cout << "cur val is " << cur_ans << endl;
				int index = dfs_order[l];
				if (mo_vals[index] != 0){
					int v = primes[mo_vals[index]];
					int coun = indices[index];
					// cout << "this cur_ans is " << cur_ans << endl;
					// cout << "this v is " << v << " for prime " << mo_vals[index] << endl;
					if (coun==2){
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]++;
						cur_ans = (cur_ans*(v+2))%MOD;
					}
					else {
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]--;
						cur_ans = (cur_ans*(v))%MOD;
					}
				}
				indices[index]--;
				l++;
			}
			while (l > t_l){
				l--; int index = dfs_order[l];
				if (indices[index] != 0){
					if (mo_vals[index] != 0){
						int v = primes[mo_vals[index]];
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]--;
						cur_ans = (cur_ans*(v))%MOD;
					}
					indices[index]++;
				}
				else {
					indices[index] = 1;
					if (mo_vals[index] == 0){

					}
					else if (primes[mo_vals[index]]!=0){
						int v = primes[mo_vals[index]];
						cur_ans = (cur_ans*inverse(v+1))%MOD;
						primes[mo_vals[index]]++;
						cur_ans = (cur_ans*(v+2))%MOD;
					}
					else {
						primes[mo_vals[index]] = 1;
						cur_ans = (cur_ans*2)%MOD;
					}
				}
			}
			// cout << "final cur_ans is " << cur_ans << endl;
			int increm = cur_ans;
			if (queries[i].lca != 0){
				int pr = mo_vals[queries[i].lca];
				if (pr != 0){
					if (primes[pr]!=0){
						increm = (increm*inverse(primes[pr]+1))%MOD;
						increm = (increm*(primes[pr]+2))%MOD;
					}
					else {
						increm = (increm*2)%MOD;
					}
				}
			}
			ansv[queries[i].i] = (ansv[queries[i].i]*increm)%MOD;
			i++;
			t_l = queries[i].l; t_r = queries[i].r;
		}
		for (int i=0; i<q; ++i){
			cout << ansv[i] << endl;
		}
	}
	return 0;
}