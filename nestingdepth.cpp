#include <bits/stdc++.h>
using namespace std;

string solve(int l, int r, string &s, int decrem){
    if (r<l || l>r){
        return "";
    }
    
    int min_val = 100, min_ind = -1;
    for (int i=l; i<=r; ++i){
        int cur = s[i] - '0';
        if (cur < min_val){
            min_val = cur; min_ind = i;
        }
    }
    string ans = "";
    for (int i=0; i<min_val-decrem; ++i){
        ans += "(";
    }
    ans += solve(l, min_ind-1, s, min_val);
    ans += ('0'+min_val);
    ans += solve(min_ind+1, r, s, min_val);
    for (int i=0; i<min_val-decrem; ++i){
        ans += ")";
    }
    return ans;
}

signed main(){
    int t; cin >> t;
    for (int w=1; w<=t; ++w){
        string s;
        cin >> s;
        cout << "Case #" << w << ": " << solve(0, s.length() - 1, s, 0) << endl;
    }
}
