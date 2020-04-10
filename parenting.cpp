#include <bits/stdc++.h>
using namespace std;
struct activ {
    int left, right, i;
};
bool comparator(const activ &l, const activ &r){
    if (l.left == r.left)
        return l.right < r.right;
    return l.left < r.left;
}

signed main(){
    int t; cin >> t;
    for (int w=1; w<=t; ++w){
        int n; cin >> n;
        activ vals[n];
        for (int i=0; i<n; ++i){
            cin >> vals[i].left >> vals[i].right;
            vals[i].i = i;
        }
        sort(vals, vals+n, comparator);
        bool posib = 1;
        char ans[n];
        int one = vals[0].right, two = vals[1].right;
        int one_ind = vals[0].i, two_ind = vals[1].i;
        if (one < two){
            one = vals[1].right; two = vals[0].right;
            one_ind = vals[1].i; two_ind = vals[0].i;
        }
        ans[vals[0].i] = 'C'; ans[vals[1].i] = 'J';
        for (int i=2; i<n; ++i){
            char cur = 'C';
            if (vals[i].left < min(one, two)){
                posib = 0; break;
            }
            else if (vals[i].left < one){
                if (ans[one_ind]=='C') cur='J';
            }
            else if (vals[i].left < two){
                if (ans[two_ind]=='C') cur='J';
            }
            if (vals[i].right > one){
                two = one; two_ind = one_ind;
                one = vals[i].right; one_ind = i;
            }
            else {
                two = vals[i].right; two_ind = i;
            }
            ans[vals[i].i] = cur;
            
        }
        cout << "Case #" << w << ": ";
        if (posib){
            for (int i=0; i<n; ++i)
                cout << ans[i];
            cout << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
