class Solution {
public:
    string nextClosestTime(string time) {
        //Converting the given time into minutes
        int mins=((time[0]-'0')*10+(time[1]-'0'))*60;
        mins+=((time[3]-'0')*10+(time[4]-'0'));

        //Inserting all the digits from the given time in a Set
        unordered_set<int> digits;
        for(int i=0; i<time.size(); i++)
            digits.insert(time[i]-'0');

        while(true){
            //Incrementing by one and checking if the new time is valid
            mins=(mins+1)%(24*60);
            int nextTime[4]={mins/60/10, mins/60%10, mins%60/10, mins%60%10};//Insert all the digits of the new time in an array

            bool isValid=true;
            for(int i=0; i<4; i++)
                if(!digits.count(nextTime[i]))
                    isValid=false;

                if(isValid)
                    return to_string(mins/60/10) + to_string(mins/60%10) + ":" +to_string(mins%60/10) + to_string(mins%60%10);
        }
    }
};
