// ----a----|
//  --b--   |
//     --c- |
//          |--d--- |
//          | --e---|
//          |  f    |
//          |    g  |
//          |       |--h-
//          |       | --i---
//          |       |  --j---
// ababcbaca|defegde|hijhklij
class Solution {
public:
    vector<int> partitionLabels(string s) {

        // result storage
        vector<int> result;

        // storage for the beginnings and endings of spans, indexed by letter.
        int beginnings[26];
        int endings[26];
        fill_n(beginnings, 26, -1);
        fill_n(endings, 26, -1);

        // Loop through the string a single time.
        // * The first time we find a character, record it as the beginning of
        //   the span of the string that contains it.
        // * Every time we find a character, that location becomes the new end
        //   of the span.
        for (int i = 0; i < s.size(); i++) {
            if (beginnings[s[i] - 'a'] == -1)
                beginnings[s[i] - 'a'] = i;
            endings[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> spans;
        for (int i = 0; i < 26; i++) {
            // Skip spans for all characters that were not actually present in
            // the input.
            if (beginnings[i] == -1)
                continue;
            spans.push_back(make_pair(beginnings[i], endings[i]));
        }
        // Sort the spans by their starting location.
        sort(spans.begin(), spans.end(), [](pair<int,int> a, pair<int,int> b) {
                                             return a.first < b.first;
                                         });

        // In this last step, we merge the spans together and compute their
        // lengths.
        int begin = -1;
        int end = -1;
        for (auto p : spans) {
            if (begin == -1) {
                // Start the first span
                begin = p.first;
                end = p.second;
            } else {
                if (p.first < end) {
                    // This span begins inside of the existing span, and we may
                    // need to expand it if the end of this character's span is
                    // past the end of the span being built. If it's not, then
                    // this span is contained entirely within the span under
                    // construction already and we don't need to do anything.
                    if (p.second > end)
                        end = p.second;
                } else {
                    // This character's span starts after the span being built,
                    // so we can consider this a break point in the input.
                    // Record the span in the results and start building a new
                    // span.
                    result.push_back(end - begin + 1);
                    begin = p.first;
                    end = p.second;
                }
            }
        }
        // Finish off the results array here because the other push_back call
        // above only happens when iterating over an item in the `spans`.
        result.push_back(end - begin + 1);
        
        return result;
    }
};
