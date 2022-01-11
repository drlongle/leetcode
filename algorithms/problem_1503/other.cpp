/*
If two ants bump into each other and change directions, it's the same as if these ants continue as nothing happens.

So, we can think about that plank as a two-way street. So, find the maximum units that any ant needs to travel.
*/
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        return max(left.empty() ? 0 : *max_element(begin(left), end(left)),
                   n - (right.empty() ? n : *min_element(begin(right), end(right))));
    }
};