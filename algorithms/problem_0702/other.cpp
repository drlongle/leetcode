class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        //get the right bound of the array
        int r = 1;
        while(reader.get(r) < target){
            r = r << 1;
        }
        int l = r >> 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(reader.get(m) > target) r = m - 1;
            else if(reader.get(m) < target) l = m + 1;
            else return m;
        }
        return -1;
    }
};
