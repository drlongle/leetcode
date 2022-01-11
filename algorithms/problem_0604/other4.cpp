class StringIterator {
    deque<char> stc;
    deque<int> sti;
public:
    StringIterator(string compressedString) {
        for(int i=0; i<compressedString.size(); ){
            stc.push_back(compressedString[i]);
            int num=0;
            int j=i+1;
            while(j<compressedString.size() && isdigit(compressedString[j])){
                num = num*10 + (compressedString[j] - '0');
                j++;
            }
            sti.push_back(num);
            i = j;
        }
    }

    char next() {
        if(!sti.empty()){
            int n = sti.front();
            sti.pop_front();
            char c =  stc.front();
            if(n-1 == 0){
                stc.pop_front();
            }else{
                sti.push_front(n-1);
            }
            return c;
        }
        return ' ';
    }

    bool hasNext() {
        return !sti.empty();
    }
};
