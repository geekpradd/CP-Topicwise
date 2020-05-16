#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t; cin >> t;
    while (t--){
        int n, x; cin >> n >> x;
        vector<int> freq(100001, 0);
        vector<int> andx(100001, 0);
        int best = 10000;
        for (int i=0; i<n; ++i){
            int z; cin >> z;
            if (freq[z]!=0){
                best = 0;
                break;
            }
            if (andx[z]!=0){
                best = 1;
            }
            int a = (x&z);
            if (freq[a]!=0){
                best = 1;
            }
            if (andx[a]!=0){
                if (2 < best)
                    best = 2;
            }
            freq[z]++;
            andx[a]++;
        }
        if (best == 10000){
            cout << -1 << endl;
        }
        else {
            cout << best << endl;
        }
    }
}
    