class TweetCounts {
    unordered_map<string, int>f = {{"minute",60}, {"hour",3600},{"day", 86400}};//86400 = 60*60*24 sec in a day
    unordered_map<string, vector<int>>m;//name:list of times
    
public:
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res;
        for (int i=0; i<=(endTime-startTime)/f[freq]; i++) 
            res.push_back(0);
        
        for (int time : m[tweetName]) {
            if (time>=startTime && time<=endTime){
                int index = (time - startTime) / f[freq];
                res[index]++;
            }
        }
        return res;
    }
};
