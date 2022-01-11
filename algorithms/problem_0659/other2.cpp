/*
We don't need to actually store each sequence. Instead, we just need to know (1) the number of sequences that end at a particular element, and (2) the size of each of those sequences. To implement this, we can have an unordered map backs to represent the sequences: backs[key] returns a priority queue (smallest value at top) of the sizes of all sequences that end with element key. Now that we have (1) and (2), we can implement the algorithm above without knowing each particular sequence.

For each num in nums, if there exists any sequence that ends with num-1 (i.e. if backs[num-1] is a non-empty priority queue), then find such a sequence with the smallest possible size (get the smallest value from the priority queue at backs[num-1]). Now, the sequence will be extended by 1 since we will add num to it. So pop the smallest value count from the priority queue at backs[num-1], and add a new value count+1 to the priority queue at backs[num].

If no sequence was found that ends in num-1 (i.e. backs[num-1] is empty), then create a new sequence. In other words, add 1 to the priority queue at backs[num].
 */

class Solution {
public:
	bool isPossible(vector<int>& nums)
	{
		unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> backs;

		// Keep track of the number of sequences with size < 3
		int need_more = 0;

		for (int num : nums)
		{
			if (! backs[num - 1].empty())
			{	// There exists a sequence that ends in num-1
				// Append 'num' to this sequence
				// Remove the existing sequence
				// Add a new sequence ending in 'num' with size incremented by 1 
				int count = backs[num - 1].top();
				backs[num - 1].pop();
				backs[num].push(++count);

				if (count == 3)
					need_more--;
			}
			else
			{	// There is no sequence that ends in num-1
				// Create a new sequence with size 1 that ends with 'num'
				backs[num].push(1);
				need_more++;
			}
		}
		return need_more == 0;
	}
};
