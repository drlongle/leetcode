class Solution {
    multiset <double> arr;
    void insert(double x){
        arr.insert(x);
    }
    void remove(double x){
        arr.erase(arr.find(x));
    }
    double getMedian(){
        int n = arr.size();
        double a = *next(arr.begin(), n / 2 - 1);
        double b = *next(arr.begin(), n / 2);
        if(arr.size() & 1)return b;
        return (a + b) / 2.0;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector <double> ans;
        arr.clear();
        for(int i = 0; i < k; i++){
            insert(nums[i]);
        }
        for(int i = k, j = 0; i <= nums.size(); i++, j++){
            if (i < nums.size())
            {
                ans.push_back(getMedian());
                remove(nums[j]);
                insert(nums[i]);
            }
            else
                ans.push_back(getMedian());
        }

        return ans;
    }
};
