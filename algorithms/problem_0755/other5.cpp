class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V-- > 0)
        {
            heights[fall(heights, K)]++;
        }
        return heights;
    }

    int fall(const vector<int>& heights, const int &K)
    {
        int fall = K, i;
        for (i = K - 1; i >= 0; i--)
        {
            if (heights[i] > heights[fall])
            {
                break;
            }
            if (heights[i] < heights[fall])
            {
                fall = i;
            }
        }
        if (fall != K)
        {
            return fall;
        }
        for (i = K + 1; i < heights.size(); i++)
        {
            if (heights[i] > heights[fall])
            {
                break;
            }
            if (heights[i] < heights[fall])
            {
                fall = i;
            }
        }
        return fall;
    }
};
