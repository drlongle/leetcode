vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
{
    vector<int> res;
    int n = queries.size();
    int m = words.size();

    vector<int> wCount(m, 0);
    for (int i = 0; i < m; i++)
        wCount[i] = f(words[i]);

    sort(wCount.begin(), wCount.end());

    for (int i = 0; i < n; i++) {
        int q = f(queries[i]);
        auto up = upper_bound(wCount.begin(), wCount.end(), q);

        if (up == wCount.end())
            res.push_back(0);
        else
            res.push_back(wCount.end() - up);
    }

    return res;
}

int f(string s)
{
    int count = 0;
    char minChar = s[0];

    for (char c : s) {
        if (c == minChar)
            count++;
        else if (c < minChar) {
            minChar = c;
            count = 1;
        }
    }

    return count;
}
