class StringIterator {
private: int count, i, n;
    string copy;
    char curr;
public:
    StringIterator(string compressedString) {
        n = compressedString.size();
        i = 0;
        count = 0;
        copy = compressedString;
    }

    char next() {
        if(count == 0){
            if(i >= n) return ' ';
            curr = copy[i++];
            while(i < n && copy[i] >= '0' && copy[i] <= '9'){
                count = 10 * count + (copy[i] - '0');
                i++;
            }
        }
        count--;
        return curr;
    }

    bool hasNext() {
        return i < n || count > 0;
    }
};
