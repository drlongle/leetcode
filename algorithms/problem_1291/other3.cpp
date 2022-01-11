class Solution {
public:
    void append(string num,vector<int>& ans,int low,int high)
    {
        if(num.size()>to_string(high).size())
            return;
        if(stoi(num)>=low && stoi(num)<=high)
        {
            ans.push_back(stoi(num));
        }
        if(num[num.size()-1]=='9')
            return;
        append(num+char(num[num.size()-1]+1),ans,low,high);
        num=num.substr(0,num.size()-1);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            append(to_string(i),ans,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
