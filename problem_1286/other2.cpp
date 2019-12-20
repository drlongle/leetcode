class CombinationIterator {
public:
    vector<string>store;
    int currentIndex;
    
    void preCompute(int i, int l, string temp, string &characters){
        if(l == 0){
            store.push_back(temp);
            return;
        }

        if(i == characters.size()) return;

        //include current
        temp.push_back(characters[i]);
        preCompute(i+1,l-1,temp,characters);
        
        //exclude cuurent
        temp.pop_back();
        preCompute(i+1,l,temp,characters);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        store.clear();
        currentIndex = 0;
        preCompute(0,combinationLength, "", characters);
    }
    
    string next() {
        return store[currentIndex++];
    }
    
    bool hasNext() {
        return (currentIndex < store.size());
    }
};
