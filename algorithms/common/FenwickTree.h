#pragma once

#include <vector>

class FenwickTree {
    using vi = std::vector<int>;

  private:
    vi ft; // recall that vi is: typedef vector<int> vi;
    int LSOne(int i) { return i & (-i); }

  public:
    FenwickTree(int n) { ft.assign(n + 1, 0); } // init n + 1 zeroes
    int rsq(int b) {                            // returns RSQ(1, b)
        int sum = 0;
        for (; b; b -= LSOne(b))
            sum += ft[b];
        return sum;
    }                       // note: LSOne(S) (S & (-S))
    int rsq(int a, int b) { // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) { // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};
