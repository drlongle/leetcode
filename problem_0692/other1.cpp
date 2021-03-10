class Word
{
public:
    string word;
    size_t freq;

    Word(string const &word, size_t freq)
            :
            word(word),
            freq(freq)
    {}

    bool operator<(Word const &other) const
    {
        if (freq == other.freq)
            return word < other.word;

        return freq > other.freq;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> const &words, size_t k)
    {
        unordered_map<string, size_t> library;
        for (size_t idx = 0; idx < words.size(); ++idx)
        {
            auto it = library.find(words[idx]);
            if (it == library.end())
                library[words[idx]] = 1;
            else
                it->second += 1;
        }

        priority_queue<Word> orderedWords;
        for (auto it : library)
        {
            Word word(it.first, it.second);
            orderedWords.push(word);
            if (orderedWords.size() > k)
                orderedWords.pop();
        }

        vector<string> output(k);
        for (size_t idx = 0; idx < k; ++idx)
        {
            output[k - idx - 1] = orderedWords.top().word;
            orderedWords.pop();
        }

        return output;
    }
};
