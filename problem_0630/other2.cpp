/*
Sort the elements in non-decreasing order of deadline.
*/
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int>pq; //using a priority queue so that the courses are sorted in the descending order of time taken
        int time_taken= 0;
        for(auto c : courses) {
            if(time_taken+c[0]<=c[1]) //if taking the current course doesn't exceed the deadline. Then add to the priority queue
            {
                time_taken+=c[0];
                pq.push(c[0]);
            }
            else {
                if(!pq.empty() && pq.top()>c[0])  //if the current course takes more time than the maximum of all the selected courses, then there is no way the current course can be included.
                {
                    int top = pq.top();
                    pq.pop();
                    time_taken-=top;
                    pq.push(c[0]);
                    time_taken+=c[0];
                }
            }
        }
        return pq.size();
    }
};
