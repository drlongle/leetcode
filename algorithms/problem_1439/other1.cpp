/*
The idea behind this solution is to add row by row (and to do so with the help of a priority queue which holds the smallest k sums). First, for each column, only loop k times since the values are sorted. Second, for each column, if the size of the priority queue exceeds k, check if the value added to the priority queue is same as the value at the top. If so, pop and break from the loop to stop adding values in that row (because all values that occur after will also be greater). I have included comments to make it easier to understand.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int> pq;
        int rowsize = mat.size();
        int colsize = mat[0].size();
        for(int i = 0; i<colsize && i<k; i++)
        {
            pq.push(mat[0][i]);//push all values in the first row to the priority queue as long as i<k
        }
        for(int j = 1; j<rowsize; j++)
        {
            priority_queue<int> pqnew;//create a new priority queue for each row
            while(!pq.empty())
            {
                int hold = pq.top();//get the value at the top of the priority queue 
                pq.pop();//pop the value at the top
                for(int i = 0; i<colsize && i<k; i++)//loop through all columns in current row
                {
                    pqnew.push(hold+mat[j][i]);//add the value at the top of priority queue to the value in the current index;
                    if(pqnew.size()>k){//check if the size of the priority queue is greater than k
                        if(pqnew.top() == hold+mat[j][i])//check if the value added recently is the value to be popped from the queue
                        {
                            pqnew.pop();//pop the value from the new queue
                            break;//exit the loop
                        }
                        pqnew.pop();//pop the value because it exceeds the size of the priority queue
                    }
                }
            }
            
            pq=pqnew;//copy values from pqnew to pq            
        }
        return pq.top();//return the value at the top (represents the kth smallest)
    }
};
