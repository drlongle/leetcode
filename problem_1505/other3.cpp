/*
If we want to construct the mininal number, we need to force the leftmost digit as small as possible.
So we can go though the string from left to right, pick the smallest one while the swap operation number
does not exceeding the threshold(at first it is K). And we do the same operation for the next digit,
until we run out our operations.

We can easily find a O(n^2) algorithm following this idea. But it is not YOUXIU (good) enough, we need to optimize it.

In general, we use three steps to pick digits from left to right.

Calculate the right most index(1-based) we can pick in the threshold;
Pick the smallest one(among smallest ones we choose the left most one), and declare that it has been picked so we can not pick it again;
Update the threshold.
We can use Segment Tree. I won't talk about basic knowledge of segment tree(without lazy-tag) in this post,
just to show how to use it in this problem.

First let's talk about the threshold. Threshold here means the largest index that we can pick.
We can use the prefix sum to calculate it.

For instance,

original string: "1 2 4 3 5 6 7", original k = 3;
use/not state:    1 1 1 1 1 1 1 (1: not been used, 0: used);
prefix sum:       1 2 3 4 5 6 7 ;
So the largest index we can pick is 4 = k + 1;
Another instance:

original string: "1 4 2 5 6 7", k = 2;
use/not state:    0 1 0 1 1 1 (1: not been used, 0: used);
prefix sum:       0 1 1 2 3 4; 
So the largest index we can pick is 5 since presum[5] = 3 = k + 1;

*/

typedef long long ll;
const int N =30010;
ll w[N];
ll st[N];

struct Node {
    ll l,r;
    ll minv, idx, sum;
} tree[4*N];

void push_up(Node& a, Node& b, Node & c) {
    if(b.minv <= c.minv) {
        a.minv = b.minv;
        a.idx = b.idx;
    } else {
        a.minv = c.minv;
        a.idx = c.idx;
    }
    a.sum = b.sum + c.sum;
}

void push_up(ll u) {
    push_up(tree[u], tree[2*u], tree[2*u+1]);
}

void build(ll u, ll l, ll r) {
    tree[u].l = l;
    tree[u].r = r;
    if(l == r) {
        ll b = w[l];
        tree[u].minv = b;
        tree[u].idx = l;
        tree[u].sum = st[l];
    } else {
        ll mid = (l + r) / 2;
        build(2*u, l, mid);
        build(2*u+1, mid+1, r);
        push_up(u);
    }
}

void update(ll u, ll idx, ll x) {
    if(tree[u].l == tree[u].r) {
        tree[u].minv = x;
        tree[u].sum = 0;
        st[tree[u].l] = 0;
    } else {
        ll mid = (tree[u].l + tree[u].r)/2;
        if(idx <= mid) update(2*u, idx, x);
        else update(2*u+1, idx, x);
        push_up(u);
    }
}

Node query(ll u, ll l, ll r) {
    if(tree[u].l >= l && tree[u].r <= r) {
        return tree[u];
    } else {
        ll mid = (tree[u].l + tree[u].r)/2;
        if(l > mid) {
            return query(2*u+1, l, r);
        } else if (r <= mid) {
            return query(2*u, l, r);
        } else {
            auto left = query(2*u, l, r);
            auto right = query(2*u+1, l, r);
            Node res;
            push_up(res, left, right);
            return res;
        }
    }
}

int get_idx(int presum, int len) {
    int l = 1;
    int r = len;
    int res = len;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(query(1, 1, mid).sum >= presum) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        if(k > n*(n-1)/2) {
            sort(num.begin(), num.end());
            return num;
        }
        return solve(num, k);
    }
    void init(string & num) {
        // build the SegTree;
        int n = num.size();
        memset(tree, 0, sizeof tree);
        for(int i = 1; i <= n; i ++) w[i] = num[i-1] - '0';
        for(int i = 1; i <= n; i ++) st[i] = 1;
        build(1, 1, n);
    }
    string solve(string & num, int k) {
        init(num);
        string res;
        while(k) {
            int max_sum = min(k+1, (int)num.size());
            int threshold = get_idx(max_sum, num.size());
            Node curr = query(1, 1, threshold);
            if(curr.minv == 10) break;
            res.push_back(curr.minv + '0');
            update(1, curr.idx, 10);
            k -= query(1, 1, curr.idx).sum;
        }
        for(int i = 1; i <= num.size(); i ++) {
            if(st[i] == 1) {
			    // unused digits
                res.push_back(num[i-1]);
            }
        }
        return res;
    }
};
