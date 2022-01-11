// maxRight is the max position that we can reach from the first position

bool canJump(vector<int>& nums)
{
	int maxRight = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i <= maxRight)
		{
			maxRight = max(maxRight, i + nums[i]);
		}
		if (maxRight >= nums.size() - 1)
		{
			return true;
		}
	}
	return false;
}

