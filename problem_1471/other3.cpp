int median;
struct compare {
    bool operator()(const int &a, const int &b) {
        return (abs(a-median) > abs(b-median)) || (abs(a-median) == abs(b-median) && a>b);
    }
} compare;

class Solution {
public:    
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());                   // Sort first to find the median.
        median = arr[(arr.size()-1)/2];                 // Find median.
        sort(arr.begin(), arr.end(), compare);          // Sort again based on a specific way.
        return vector<int>(arr.begin(), arr.begin()+k); // Return the answer.
    }
};
