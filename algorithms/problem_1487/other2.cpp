class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> m;// A map to store whether the particular name occurs how many times already
        for(int i=0;i<names.size();i++)
        {
            if(m.find(names[i])!=m.end())// if the name already came
            {
                int k=m[names[i]];// it contains the number in brackets
                while(m.find(names[i]+"("+to_string(k)+")")!=m.end())
                {
                    k++;// Increase number until that didn't exist
                    m[names[i]]++;//mean while update in the map too
                }
                m[names[i]]++;// Recently we will use one more number so increment
                 names[i]=names[i]+"("+to_string(k)+")";
            }
            m[names[i]]=1;// Here we are storing  for example ...abc(1)=1 and abc(2)=1 it means abc(1) occcured one time, and abc=2 it means abc occured 2 times.
			/*
			Suppose you have a file named ABC occurring twice, we will store ABC with occurrence =2 and ABC(1) with occurrence =1... It helps when we get another file with name ABC(1) we can store like ABC(1)(1)
			*/
			
        }
        return names;
    }
};
