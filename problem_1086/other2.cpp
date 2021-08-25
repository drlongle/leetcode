class Solution {
    int cal_avg(priority_queue<int, vector<int>, greater<int>> A)
    {
        long sum = 0; int c = 0;
        while(!A.empty())
        {
            c++;
            int t = A.top();
            A.pop();
            sum+=t;
        }
        return sum/c;
    }
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> A;
        for(int i=0; i<items.size(); i++)
        {
            if(A[items[i][0]].size()<5)
                A[items[i][0]].push(items[i][1]);
            else
            {
                A[items[i][0]].push(items[i][1]);
                A[items[i][0]].pop();
            }
        }
        vector<vector<int>> ret;
        for(auto it:A)
        {
            vector<int> temp;
            temp.push_back(it.first);
            temp.push_back(cal_avg(it.second));
            ret.push_back(temp);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
