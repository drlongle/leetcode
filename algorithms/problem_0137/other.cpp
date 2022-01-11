int singleNumber(vector<int>& nums)
{
	int res;
	unordered_map<int,int>temp;
	for(int i=0;i<nums.size();i++)
	{
		++temp[nums[i]];
	}
	
	for(auto &x:temp)
	{
		if(x.second<2)
			return x.first;
	}
	return 0;
}
