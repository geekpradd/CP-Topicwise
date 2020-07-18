#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t; scanf("%d", &t);
    while (t--){
        int n; scanf("%d", &n);
        int a[n], b[n];
        map<int, int> freq_a; map<int, int> freq_b;
        for (int i=0; i<n; ++i) scanf("%d", &a[i]);
        for (int i=0; i<n; ++i) scanf("%d", &b[i]);
    
        int least = 2*1000000000;
        for (int i=0; i<n; ++i){
            if (freq_a.count(a[i])) freq_a[a[i]]++;
            else
                freq_a[a[i]] = 1;
            
            if (freq_b.count(b[i])) freq_b[b[i]]++;
            else
                freq_b[b[i]] = 1;
            least = min(a[i],least);
            least = min(b[i], least);
        }
 
        bool pos = 1;
        vector<int> a_b, b_a;
        for (int i=0; i<n; ++i){
            int fir = freq_a[a[i]];
            int second = (freq_b.count(a[i]) ? freq_b[a[i]] : 0);
            if ((fir + second) % 2){
                pos = 0; break;
            }
            if (second > fir){
                int total = (second - fir)/2;
                for (int j=0; j<total; ++j) b_a.push_back(a[i]);
            }
            else if (fir > second){
                int total = (fir - second)/2;
                for (int j=0; j<total; ++j) a_b.push_back(a[i]);
            }
            freq_a[a[i]] = 0, freq_b[a[i]] = 0;
            
            fir = freq_b[b[i]];
            second = (freq_a.count(b[i]) ? freq_a[b[i]] : 0);
            if ((fir + second) % 2){
                pos = 0; break;
            }
            if (second > fir){
                int total = (second - fir)/2;
                for (int j=0; j<total; ++j) a_b.push_back(b[i]);
            }
            else if (fir > second){
                int total = (fir - second)/2;
                for (int j=0; j<total; ++j) b_a.push_back(b[i]);
            }
            freq_a[b[i]] = 0, freq_b[b[i]] = 0;
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
