struct node
{
    bool end;
    node* next[26];
    node()
    {
        end=0;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
};
class StreamChecker {
public:
    node* root=new node();
    string s="";
    StreamChecker(vector<string>& words) {
        for(auto x : words)
        {
            reverse(x.begin(),x.end());
            node* temp=root;
            for(int i=0;i<x.size();i++)
            {
                if(temp->next[x[i]-'a']==NULL)
                {
                    temp->next[x[i]-'a']=new node();
                }
                temp=temp->next[x[i]-'a'];
            }
            temp->end=1;
        }
    }
    bool search(node* root,int i,string &s)
    {
        if(root->end==1){return 1;}
        if(i<0){return 0;}
        if(root->next[s[i]-'a']!=NULL)
        {
            return search(root->next[s[i]-'a'],i-1,s);
        }
        return 0;
    }

    bool query(char letter) {
        s+=letter;
        return search(root,s.size()-1,s);
    }
};
