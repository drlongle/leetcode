struct Trie{
    array<Trie*, 26> next = {};
};

class Solution
{
public:
    int countDistinct(string s)
    {
        list<Trie> mem = {};
        Trie trie = {};

        for( size_t i = 0; i < s.size(); ++i )
        {
            Trie* curr = &trie;

            for( size_t e = i; e < s.size(); ++e )
            {
                if( curr->next[s[e]-'a'] == nullptr )
                {
                    mem.push_front( Trie() );
                    curr->next[s[e]-'a'] = &mem.front();
                }
                curr = curr->next[s[e]-'a'];
            }
        }
        return mem.size();
    }
};
