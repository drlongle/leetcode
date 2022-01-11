class ZigzagIterator {
public:
    vector<int> v1, v2;
    bool curr;
    int i1 = 0,i2 = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2):v1(v1),v2(v2) {
        curr = true;
    }

    int next() {
        int ret = 0;
        if (curr){
            if (i1 < v1.size()){
                ret = v1[i1];
                i1++;
            }
            else{
                ret = v2[i2];
                i2++;
            }
        }
        else{
            if (i2 < v2.size()){
                ret = v2[i2];
                i2++;
            }
            else{
                ret = v1[i1];
                i1++;
            }

        }
        curr = !curr;

        return ret;

    }

    bool hasNext() {
        if (i1 < v1.size() || i2 < v2.size()) return true;
        else return false;
    }
};
