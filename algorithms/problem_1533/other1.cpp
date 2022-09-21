class Solution {
  public:
    int getIndex(ArrayReader &reader) {
        int low = 0, high = reader.length() - 1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            bool even = (high - low) % 2;
            int cmp = reader.compareSub(low, mid, mid + even, high);
            if (cmp == 0)
                return mid;

            if (cmp > 0)
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }
};
