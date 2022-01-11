class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        queue <int> squeue;
        for (int i = 0; i < students.size(); i++)  {
            squeue.push(students[i]);
        }
        int j = 0;
        while ( j < sandwiches.size()) {
            if (count == squeue.size()) {
                return squeue.size();
            }
            if (squeue.front() == sandwiches[j])  {
                count = 0;
                squeue.pop();
                j++;
            }
            else {
                squeue.push(squeue.front());
                squeue.pop();
                count ++;
            }
        }
        return squeue.size();
    }
};
