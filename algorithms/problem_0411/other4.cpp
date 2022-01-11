/*
The idea is to find all valid masks with minimum bits set first, and then find the minimum abbreviation recursively.
For each bit in a key built from diff of target and word, there could be below cases:

- If a bit is 0, which means the char in word is same as the corresponding char in target, the bit has no effect to
the final result on this word
- If a bit is 1 and it is the only bit set, i.e. the only difference from target, then that char is required, i.e.
the bit must be set in final result
- If there are 2 or more bitsets, all the bits are optional, i.e. as long as one of them is set in final result,
it will make the abbreviation distinct between target and this word.
- If a bit is optional for word1 but required for word2, we can ignore word1 because it is already covered by word2.
- For example "apple" ["xpple", "xpplx"] => [10000, 10001] => [10000] => "a4
- if a bit is optional for both word1 and word2, we can take that bit to cover both words and at same time, minimize
the number of set bits. For example "apple" ["xppze", "xpplx"] => [10010, 10001] => [10000] => "a4
- Therefore, a valid abbreviation key will be [required bits] | [ a mask with minimum number of '1' which ensure
at least one optional bit set for each word], steps as below:
- Generate keys for each word dictionary, if required (only 1 bit set), put it to required mask. If optional, put to
the distinct list.

Check all keys in distinct list, if covered by required , remove from the list
Make all keys distinct, i.e. distinct[i] & distinct[j] == 0 if i != j
For remaining keys in distinct, take required as base mask and then pick up 1 optional bit from each key recursively,
and check the length of the abbreviation.
 */

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size();
        vector<int> distinct;
        int required = 0;
        for (auto word : dictionary) {
            if (word.size() != n) continue;
            int key = getKey(target, word);
            if ((key & (key-1)) == 0) required |= key; // only 1 distinct char, so it is requried
            else distinct.push_back(key);
        }

        // check if the required bits can cover any keys
        if (required) {
            vector<int> tmp;
            for (auto x : distinct) {
                // if no overlapped bits, it is not covered
                // need to handle them later
                if ((x & required) == 0) tmp.push_back(x);
            }
            distinct.swap(tmp);
        }

        // make all remaining keys distinct each other
        vector<int> tmp;
        for (auto x : distinct) {
            bool merged = false;
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] & x) {
                    tmp[i] &= x;
                    merged = true;
                    break;
                }
            }
            if (!merged) tmp.push_back(x);
        }
        distinct.swap(tmp);

        // now only distinct keys left, recursively check the length of each valid key
        int res = pow(2, n) - 1;
        solve(distinct, 0, required, n, res);
        return getAbbre(target, res);
    }

    void solve(vector<int>& v, int idx, int key, int len, int& out) {
        // all keys combined, check length
        if (idx == v.size()) {
            if (getLen(key, len) < getLen(out, len)) {
                out = key;
            }
        }
        else { // append remaining keys
            int cand = v[idx];
            while(cand) {
                int mask = cand;
                cand &= cand-1;
                mask ^= cand;
                solve(v, idx+1, key | mask, len, out);
            }
        }
    }

    string getAbbre(string& target, int key) {
        int n = target.size();
        string res;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((key & (1 << (n-1-i)))) {
                if (count) res += to_string(count);
                res.push_back(target[i]);
                count = 0;
            }
            else count++;
        }
        if (count) res += to_string(count);
        return res;
    }

    int getLen(int key, int len) {
        int count = len;
        int n = 1 << len;
        for (int i = 3; i < n; i <<= 1) {
            if ((key & i) == 0) count--;
        }
        return count;
    }

    int getKey(string& s1, string& s2) {
        int key = 0;
        for (int i = 0; i < s1.size(); i++) {
            key <<= 1;
            key += s1[i] == s2[i] ? 0 : 1;
        }
        return key;
    }
};
