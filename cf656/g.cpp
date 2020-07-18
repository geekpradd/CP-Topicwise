#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E13 10000000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define edge pair<int, pair<int, int> > 
#define REP0(i, n) for (int i=0; i<n; ++i)
#define REP1(i, n) for (int i=1; i<=n; ++i)
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
int n, m;
int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp % 2)
		return (res*base)%MOD;
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}

void dfs(int cur, vector<int>& visited, vector<ii> adj[], vector<bool> &special, vector<int> &base, vector<int> &total, int status, int prev, int starter, int &sc){
    visited[cur] = 1;
    if(special[cur])
        sc++;
    // DUMP(cur);
    // DUMP(prev);
    // DUMP(adj[cur]);
    for (ii to: adj[cur]){
        // DUMP(to);
        if (to.first == prev) continue;
        if (visited[to.first] && to.first != starter) continue;
            
        if (!status && special[cur]){
            base.pb(to.second);
            if (visited[to.first]) break; 
            dfs(to.first, visited, adj, special, base, total, 1-status, cur, starter, sc);
        }
        else if (!status){
            total.pb(to.second);
            if (visited[to.first]) break; 
            dfs(to.first, visited, adj, special, base, total, status, cur, starter, sc);
        }
        else if (special[cur]){
            total.pb(to.second);
            if (visited[to.first]) break; 
            dfs(to.first, visited, adj, special, base, total, 1-status, cur, starter, sc);
        }
        else {
            base.pb(to.second);
            if (visited[to.first]) break; 
            dfs(to.first, visited, adj, special, base, total, status, cur, starter, sc);
        }
    }



}
void solve(){
    int n;  cin >> n;
    int a[n], b[n];
    vector<int> freq(n+1, 0);
    vector<int> freq_a(n+1, 0), freq_b(n+1, 0);
    REP0(i, n){
        cin >> a[i];
        freq[a[i]]++;
        freq_a[a[i]]++;
    }
    REP0(i, n){
        cin >> b[i];
        freq[b[i]]++;
        freq_b[b[i]]++;
    }
    bool pos = 1;
    REP1(i, n){
        if (freq[i] != 2) {
            pos = 0; break;
        }
    }
    if (!pos){
        d1(-1); return;
    }
    vector<ii> adj[n+1];
    vector<bool> special(n+1, 0);
    REP0(i, n){
        if (a[i] == b[i]) continue;

        adj[a[i]].pb(mp(b[i], i+1));
        adj[b[i]].pb(mp(a[i], i+1));
        if (freq_a[a[i]] == 2) special[a[i]] = 1;
        if (freq_b[b[i]] == 2) special[b[i]] = 1;
    }

    vector<int> visited(n+1, 0);
    vector<int> path;

    REP1(i, n){
        if (adj[i].size() == 0) continue;
        // DUMP(i);
        if(!visited[i]){
            // DUMP(i);
            vector<int> base, total;
            int sc = 0;
            dfs(i, visited, adj, special, base, total, 0, 0, i, sc);
            // cout << base << endl;
            // cout << total << endl;
            if (sc == 0) continue;
            if (base.size() <= total.size()){
                if (base.size() == 0){
                    for (int k:total){
                        path.pb(k);
                    }
                }
                else {
                    for (int k: base){
                        path.pb(k);
                    }
                }
                
            }
            else {
                if (total.size() == 0){
                    for (int k: base){
                        path.pb(k);
                    }
                }
                else {
                    for (int k:total){
                        path.pb(k);
                    }
                }
                
            }
        }
    }
    d1(path.size());
    for (int k: path){
        d0(k);
    }
    cout << endl;
}

signed main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t--){
        solve();
    }
}