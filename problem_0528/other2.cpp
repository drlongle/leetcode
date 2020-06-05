class Solution {
public:
    Solution(vector<int>& w) 
    {
        int n = w.size();
        sum = 0;
        cnt = 0;
        storage = new int[n];
        
        for(int i=0;i<n;++i)
        {
            sum += w[i];
            storage[cnt++] = sum;
        }
    }
    
    int pickIndex() 
    {
        if(cnt < 2) return 0;
        
        int target = rand() % sum;
        int left = 0, right = cnt - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(target >= storage[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    ~Solution()
    {
        delete[] storage;
    }
    
private:
    int *storage, sum, cnt;
};
