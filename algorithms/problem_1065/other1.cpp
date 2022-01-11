class Solution
{
    struct node_t
    {
        array<node_t*, 26> next;
        bool is_word;

        node_t() : next{}, is_word(false) {}
        ~node_t()
        {
            for (auto n : next)
                delete n;
        }
    };

public:
    vector<vector<int>> indexPairs(string text, vector<string>& words)
    {
        node_t root;
        for (const auto& w : words)
        {
            auto cur = &root;
            for (char c : w)
            {
                if (auto idx = c - 'a'; cur->next[idx])
                    cur = cur->next[idx];
                else
                    cur = cur->next[idx] = new node_t();
            }
            cur->is_word = true;
        }

        vector<vector<int>> out;
        for (int beg = 0; beg < text.size(); ++beg)
        {
            auto cur = &root;
            for (int i = beg; i < text.size(); ++i)
            {
                cur = cur->next[text[i] - 'a'];
                if (cur == nullptr)
                    break;
                else if (cur->is_word)
                    out.push_back({beg, i});
            }
        }
        return out;
    }
};
