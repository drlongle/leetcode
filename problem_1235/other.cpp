class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
	struct job
	{
            job(int i_start_time, int i_end_time, int i_profit) 
                : start_time(i_start_time), end_time(i_end_time), profit(i_profit) {}
            int start_time;
            int end_time;
            int profit;
            bool operator< (const job& i_job)
            {
                return end_time < i_job.end_time;
            }
	};

	vector<job> jobs;
	for (int i = 0; i < size(startTime); ++i)
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
	sort(begin(jobs), end(jobs));
	sort(begin(endTime), end(endTime));
	unordered_map<int, int> dp;
	int prev_end_time = -1;
	for (const auto& curr_job : jobs)
	{
            auto it = upper_bound(begin(endTime), end(endTime), curr_job.start_time);
            int start_time_pos = it == begin(endTime) ? 0 : *prev(it);
            dp[curr_job.end_time] = max(dp[prev_end_time], curr_job.profit + dp[start_time_pos]);
            prev_end_time = curr_job.end_time;
	}
	return dp[jobs.back().end_time];
    }
};
