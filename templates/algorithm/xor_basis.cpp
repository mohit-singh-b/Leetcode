#include <bits/stdc++.h>
using namespace std;

class xor_basis {
    array<long long, 63> basis{};
public:
    bool add(long long n) {
        for (int i = 62; i >= 0; i--) {
            if (!((n >> i) & 1)) continue;
            if (!basis[i]) { basis[i] = n; return true; }
            n ^= basis[i];
        }
        return false;              
    }
    long long max_xor() {
        long long res = 0;
        for (int i = 62; i >= 0; i--)
            res = max(res, res ^ basis[i]);
        return res;
    }
};