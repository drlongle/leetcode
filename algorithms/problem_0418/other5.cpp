class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        ++cols;
        int size = sentence.size();
        vector<int> wl(size, 0);
        for(int i = 0; i < size; ++i) wl[i] = sentence[i].size()+1;
        int len = accumulate(wl.begin(), wl.end(), 0);
        vector<int> rowCount = {0};
        int i = 0, row = 0, words = 0;
        do {
            int cur = 0;
            while(i < size && cur+sentence[i].size() < cols) cur += wl[i++], ++words;
            int r = cols - cur;
            words += size * (r/len), cur += (len * (r/len));
            r %= len;
            i %= size;
            while(i < size && cur+sentence[i].size() < cols) cur += wl[i++], ++words;
            rowCount.push_back(words);
            ++row;
        } while(i != 0 && row < rows);

        if(rowCount.size()-1 == rows) return rowCount.back()/size;

        int m = rows/(rowCount.size()-1), r = rows % (rowCount.size()-1);
        return (m * rowCount.back() + rowCount[r])/size;

    }
};
