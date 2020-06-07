int median;
struct compare {
    bool operator()(const int &a, const int &b) {
        return (abs(a-median) > abs(b-median)) || (abs(a-median) == abs(b-median) && a>b);
    }
} compare;

class Solution {
public:    
    vector<int> getStrongest(vector<int>& arr, int k) {
        partial_sort(arr.begin(), arr.begin()+(arr.size()-1)/2+1, arr.end());  // Just find median element correctly.
        median = arr[(arr.size()-1)/2]; // Get median.
        partial_sort(arr.begin(), arr.begin()+k, arr.end(), compare); // Sort just enough that k strongest are at the beginning.
        return vector<int>(arr.begin(), arr.begin()+k);  // Return the answer.
    }
};
