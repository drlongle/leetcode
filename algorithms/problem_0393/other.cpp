
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const unsigned int mask(0xff);
        int length, i;
        bool inFirstByte = true;
        for(auto x:data){
            x&=mask;
            if(inFirstByte){
                i=1;
                inFirstByte = false;
                bitset<sizeof(int)*8> b(x);
                int k;
                for(k = 7; b[k]==1&&k>=0;k--);
                length = 7-k;
                if(length ==1){
                    return false;
                }
                if(length ==0){
                    length = 1;
                }
                if(length>4){
                    return false;
                }
            }
            else{
                i++;
                bitset<sizeof(int)*8> b(x);
                if(b[7]!=1 || b[6]!=0){
                    return false;
                }
            }
            if(i==length){
                inFirstByte = true;
            }
        }

        return inFirstByte;
    }
};
