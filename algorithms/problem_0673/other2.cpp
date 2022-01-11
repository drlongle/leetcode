class Node {
public:
    vector<pair<int, int>> tree;
    pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.first != 0 ? make_pair(a.first, a.second + b.second) : make_pair(0, 1);
        } else {
            return a.first > b.first ? a : b;
        }
    }
    Node(int n) {
        for (int i = 0; i < 2 * n; i++)
            tree.push_back(make_pair(0, 0));
    }

    void insert(int node, pair<int, int> result) {
        tree[node] = merge(tree[node], result);
        while (node > 1) {
            node >>= 1;
            tree[node] = merge(tree[node << 1], tree[(node << 1) + 1]);
        }
    }

    pair<int, int> query(int left, int right) {
        pair<int, int> result = make_pair(0, 1);
        for (;left < right; left >>= 1, right >>= 1) {
            if (left & 1)  result = merge(result, tree[left++]);
            if (right & 1) result = merge(result, tree[--right]);
        }
        return result;
    }

    int getCount() {
        return tree[1].second;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        set<int> numsSet(nums.begin(), nums.end());
        unordered_map<int, int> numMap;
        int n = 0;
        for (auto &num : numsSet) numMap[num] = n++;
        Node* root = new Node(n);
        for (auto &num : nums) {
            int node = numMap[num] + n;
            pair<int, int> result = root->query(n, node);
            result.first++;
            root->insert(node, result);
        }
        return root->getCount();
    }
};
