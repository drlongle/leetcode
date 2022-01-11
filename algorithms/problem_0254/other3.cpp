class Solution {
public:
    
    void myrecur(int n, int j,vector<int> &arr, vector<vector<int>> &res){
        arr.push_back(n);
        res.push_back(arr);
        arr.pop_back();

        for(int i=j;i<=sqrt(n);i++){
            if(n%i==0){
                arr.push_back(i);
                myrecur(n/i,i,arr,res);
                arr.pop_back();
            }
        }

    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> arr;

        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                arr.push_back(i);
                myrecur(n/i,i,arr,res);
                arr.pop_back();
            }
        }
        return res;

    }
};
