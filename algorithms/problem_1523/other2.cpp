class Solution
{
public:
    int countOdds(int l, int h)
    {
        return h % 2 + l % 2 + (h - l - h % 2 - l % 2) / 2;
    }
};