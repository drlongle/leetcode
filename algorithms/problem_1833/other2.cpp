class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int current = 0;

        for(int cost : costs)
            min_heap.push(cost);

        while(!min_heap.empty() && coins != 0){
            coins -= min_heap.top();
            min_heap.pop();

            if(coins < 0)
                return current;

            current++;
        }

        return current;
    }
};
