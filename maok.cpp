#include <bits/stdc++.h>
#define int long long
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool prime(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

signed main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int dist = 0;
        int tot = 1;
        int orig = n;
        for (int i=2; i*i*i<=orig; ++i){
            int exp = 0;
            while (n%i==0){
                n = n/i;
                exp++;
            }
            if (exp!=0) dist++;
            tot = tot*(exp+1);
          
        }
        
        if (n!=1){
            int sqr = round(sqrt(n));
            if (prime(n, 9)){
                tot *= 2;
                dist++;
            }
            else if ((sqr)*sqr==n){
                dist++;
                tot *= 3;
            }
            else {
                dist += 2;
                tot *= 4;
            }
        } 
        
        cout << tot - dist << endl;
    }
    return 0;
}