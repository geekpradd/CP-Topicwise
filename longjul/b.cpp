#include <bits/stdc++.h>
#define ii pair<int, int>
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

signed main(){
    int t; scanf("%d", &t);
    while (t--){
        int n; scanf("%d", &n);
        int a[n], b[n];
        int least = 2*1000000000;

        for (int i=0; i<n; ++i) {
            scanf("%d", &a[i]);  least = min(a[i],least);
        }
        for (int i=0; i<n; ++i) {
            scanf("%d", &b[i]);  least = min(b[i], least);
        }
        sort(a, a+n); sort(b, b+n);

        vector<ii> a_c, b_c;
        int prev_a = a[0], prev_b = b[0];
        int c_a = 1, c_b = 1;
        for (int i=1; i<n; ++i){
            if (a[i] == prev_a){
                c_a++;
            }
            else {
                a_c.push_back(make_pair(prev_a, c_a));
                prev_a = a[i]; c_a = 1;
            }
             if (b[i] == prev_b){
                c_b++;
            }
            else {
                b_c.push_back(make_pair(prev_b, c_b));
                prev_b = b[i]; c_b = 1;
            }
        }
        a_c.push_back(make_pair(prev_a, c_a));
        b_c.push_back(make_pair(prev_b, c_b));

        // cout << a_c << endl;
        // cout << b_c << endl;
        bool pos = 1;
        vector<int> a_b, b_a;
        int a_p = 0, b_p = 0;
        for (; b_p < b_c.size(); ++b_p){
            if (a_p != a_c.size()){
                 while (a_c[a_p].first < b_c[b_p].first){
                    int count = a_c[a_p].second;
                    if (count % 2) {
                        pos = 0; break;
                    }
                    else {
                        for (int j=0; j<count/2; ++j){
                            a_b.push_back(a_c[a_p].first);
                        }
                    }
                    a_p++;
                    if (a_p == a_c.size())
                        break;
                }
            }
           
            if (pos == 0) break;
            if (a_p != a_c.size()){
                if (a_c[a_p].first == b_c[b_p].first){
                    int total = a_c[a_p].second + b_c[b_p].second;
                    if (total % 2){
                        pos = 0; break;
                    }
                    if (a_c[a_p].second > b_c[b_p].second){
                        int t = (a_c[a_p].second - b_c[b_p].second)/2;
                        for (int j=0; j<t; ++j) a_b.push_back(b_c[b_p].first);
                    }
                    else {
                        int t = (b_c[b_p].second - a_c[a_p].second)/2;
                        for (int j=0; j<t; ++j) b_a.push_back(b_c[b_p].first);
                    }
                    a_p++;
                }
                else {
                    int count = b_c[b_p].second;
                    if (count % 2) {
                        pos = 0; break;
                    }
                    else {
                        for (int j=0; j<count/2; ++j){
                            b_a.push_back(b_c[b_p].first);
                        }
                    }
                }
            }
            else {
                int count = b_c[b_p].second;
                if (count % 2) {
                    pos = 0; break;
                }
                else {
                    for (int j=0; j<count/2; ++j){
                        b_a.push_back(b_c[b_p].first);
                    }
                }
            }
        }
        while (a_p != a_c.size()){
            int count = a_c[a_p].second;
            if (count % 2) {
                pos = 0; break;
            }
            else {
                for (int j=0; j<count/2; ++j){
                    a_b.push_back(a_c[a_p].first);
                }
            }

            a_p++;
        }
        
        if (a_b.size() != b_a.size()){
            pos = 0;
        }
        if (pos == 0){
            printf("-1\n");
        }
        else {
            sort(a_b.begin(), a_b.end()); sort(b_a.begin(), b_a.end(), greater<int>());
            long long val = 0;
            for (int i=0; i<a_b.size(); ++i){
                val += min(min(a_b[i], b_a[i]), 2*least);
            }
            printf("%llu\n", val);
        }
    }
    
    return 0;
}
