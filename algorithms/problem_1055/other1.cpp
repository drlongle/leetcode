class Solution {
public:
    int shortestWay(string source, string target) {
        const int source_len = source.length();
        const int target_len = target.length();
        int target_idx = 0;
        int g_count = 0;
        while (target_idx < target_len) {
            const int start_idx = target_idx;
            int source_idx = 0;
            while (source_idx < source_len && target_idx < target_len) {
                if (source[source_idx++] == target[target_idx]) {
                    target_idx++;
                }
            } // end while src
            if (start_idx == target_idx) {
                return -1;
            }
            g_count++;
        } // end while target
        return g_count;
    }
};
