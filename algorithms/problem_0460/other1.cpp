class LFUCache {
private:
    struct node {
        int key;
        int val;
        int count;
    };
    unordered_map<int,list<node>::iterator> m;
    unordered_map<int,list<node>> freq;
    int size,cap;
    int lfreq;
public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
        lfreq=0;
    }

    int get(int key) {
        if(m.find(key)==m.end() or cap==0) return -1;
        node temp;
        temp.count = m[key]->count+1;
        temp.val = m[key]->val;
        temp.key = key;
        freq[temp.count].push_front(temp);      //Push to liked list with freq+1
        freq[temp.count-1].erase(m[key]);       //Remove from previous linked list
        if((temp.count-1) == lfreq and freq[temp.count-1].empty()) lfreq++;
        m[key]=(freq[temp.count]).begin();
        return temp.val;
    }

    void put(int key, int value) {
        if(cap==0) return;
        if(m.find(key)!=m.end()) {  //Key already exists
            m[key]->val=value;      //Update value
            get(key);               //get(key) to do the rest
        } else {                    //New Key
            if(size==cap) {
                list<node>::iterator it = freq[lfreq].end();
                it--;
                m.erase(it->key);
                freq[lfreq].pop_back();
            } else {
                size++;
            }
            node temp;
            temp.count = 1;
            temp.val = value;
            temp.key = key;
            lfreq=1;
            freq[lfreq].push_front(temp);
            m[key]=(freq[temp.count]).begin();
        }
    }
};
