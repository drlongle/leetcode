class StringIterator {
public:
    using VS = vector<string>;
    StringIterator(string S) : i{ 0 } {
        copy_if(S.begin(), S.end(), back_inserter(chars), [](auto c) { return isalpha(c); });
        transform(S.begin(), S.end(), S.begin(), [](auto c) { return isalpha(c) ? ' ' : c; });
        istringstream stream{ S };
        copy(istream_iterator<int>(stream), istream_iterator<int>(), back_inserter(counts));
        assert(chars.size() == counts.size());
        N = chars.size();
    }
    char next() {
        if (!hasNext())
            return ' ';
        auto c = chars[i];
        if (!--counts[i])
            ++i;
        return c;
    }
    bool hasNext() {
        return i < N;
    }
private:
    int i, N;
    vector<char> chars;
    vector<int> counts;
};
