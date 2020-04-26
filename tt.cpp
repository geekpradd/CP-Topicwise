#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int dist = 0;
        int tot = 1;
        int cur = -1;
        int exp = 0;
        for (int i=2; i*i<=n; ++i){
            if (n%i == 0){
                n= n/i;
                if (cur == i){
                    exp++;
                }
                else {
                    cur = i;
                    dist++;
                    tot *= (exp+1);
                    exp = 1;
                }
                i--;
            }
        }
        if (n!=1){
            if (cur == n){
                exp++;
                tot *= (exp+1);
            }
            else{
                tot *= (exp+1);
                tot *= 2;
                dist++;
            }
        }
        cout << tot - dist << endl;
    }
    return 0;
}