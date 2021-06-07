class StringIterator {
    stringstream ss;
    int i, currVal, str_length;
    char currChar;
public:
    StringIterator(string compressedString) {
        ss << compressedString;
        str_length = compressedString.length();
        i = 0; currVal = 0;
    }

    char next() {
        if (hasNext() && currVal == 0) {
            ss >> currChar;
            ss >> currVal;
            string val = to_string(currVal);
            i += (1 + val.length());
            --currVal;
            return currChar;
        } else if (currVal > 0) {
            --currVal;
            return currChar;
        }
        return ' ';
    }

    bool hasNext() {
        return i < str_length || currVal > 0;
    }
};
