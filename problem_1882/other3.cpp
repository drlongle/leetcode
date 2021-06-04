class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > q;                    //duration, idx
        priority_queue<tuple<long,int,int>, vector<tuple<long,int,int>>, greater<> > p;        //time , duration, index

        for(int i = 0; i != servers.size(); i++) q.push({servers[i], i});                      //prepare all servers for using

        int i = 0, n = tasks.size();                                      //i - iterator for tasks
        long time = 0;                                                    //for current time
        vector<int> answer(n);

        while(i < n){
            while(!p.empty() && get<0>(p.top()) == time)                    //replace servers that have ended its work for current time into queue of servers
            {q.push({get<1>(p.top()), get<2>(p.top())}); p.pop();}

            if(q.empty()) time = get<0>(p.top());                           //if we dont have any free servers - replace current time for minimal from p
            else{
                while( i != n &&  i <= time && !q.empty()){                   //if we have free servers - we put in p all possible tasks for current time
                    answer[i] = q.top().second;
                    p.push({time + tasks[i++] ,q.top().first, q.top().second});
                    q.pop();
                }
                time++;                                                       //increase time for next task
            }
        }

        return answer;
    }
};