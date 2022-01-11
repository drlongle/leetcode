
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
	int cnt = 0;
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	for (int i = 0, j = 0; i < arr1.size(); ++i) {
            while (j < arr2.size() && arr2[j] < arr1[i] - d)
                ++j;

            if (j >= arr2.size())
                return (int)arr1.size() - cnt;

            if (arr2[j] >= arr1[i] - d && arr2[j] <= arr1[i] + d)
                ++cnt;
	}

	return (int)arr1.size() - cnt;
    }
};
