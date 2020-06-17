class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {      
        int maxDay = 1e9 + 1;
        int l = 1, r = maxDay; // [); left close right open rule                            
        while(l<r){
            int mid = l + (r - l) / 2;                
            if(isValid(b, mid, m, k)) r = mid;  // use isValid to decouple the question into 2 smalll subproblems then conquer them 1 by 1            
            else l = mid + 1;
        }
        return l < maxDay ? l  : -1;
    }
    
private:
    bool isValid(const vector<int>& b, int day, int bouquets, int k){                
        for(int i = 0, cnt = 0; i < b.size(); i++)
            if(b[i] <= day){
                cnt++;
                if(cnt ==k) cnt = 0, bouquets--;
                if(bouquets == 0) return true;
            }else cnt=0;        
        return false;        
    }
};
