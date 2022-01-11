class Solution {
public:
    //comparator function
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        priority_queue<pair<int,int>> pq;
        int n=courses.size();

        //intial time is 0 we can add any course from 0;
        int time=0;

        for(int i=0;i<n;i++){
            if(pq.empty()) {
                if(time+courses[i][0]<=courses[i][1]) {
                    pq.push({courses[i][0],courses[i][1]});
                    time=time+courses[i][0];
                }
            }
            else if(time+courses[i][0]<=courses[i][1]) {
                pq.push({courses[i][0],courses[i][1]});
                time=time+courses[i][0];
            } else {
                pair<int,int> p=pq.top();
                if(p.first>courses[i][0]) {
                    pq.pop();
                    pq.push({courses[i][0],courses[i][1]});
                    time=time-(p.first-courses[i][0]);
                }
            }

        }

        return pq.size();
    }
};
