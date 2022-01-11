class StringIterator {
public:
    StringIterator(string compressedString): data_(compressedString) {
        advance();
    }
    void advance(){
        ch_ = data_[index_++];
        std::string countString;
        while(data_[index_] >= '0' && data_[index_] <= '9')
            countString += data_[index_++];

        count_ = stoi(countString);
    }
    char next() {
        if(!hasNext())
            return ' ';

        --count_;
        return ch_;
    }

    bool hasNext() {
        if(count_ > 0)
            return true;

        if(index_ >= data_.length())
            return false;

        advance();
        return true;
    }
private:
    string data_;
    char ch_;
    int count_ = 0;
    int index_ = 0;
};
