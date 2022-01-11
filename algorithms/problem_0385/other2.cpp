
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger *> st; // the non-closed nested lists (haven't seen a ']')
        NestedInteger dummy;
        st.push(&dummy); 
        int n = s.size();
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[j] != '[' && s[j] != ']' && s[j] != ',') ++j;
            if(j > i){
                int val = stoi(s.substr(i, j - i));
                st.top()->add(NestedInteger(val));
            }
            if(j == n) break;
            if(s[j] == '['){
                // open a new nested list
                st.top()->add(NestedInteger());
                auto p = &(st.top()->getList().back());
                st.push(p);
            }else if(s[j] == ']'){
                // close the current nested list
                st.pop();
            }
            i = j + 1;
        }
        return dummy.getList()[0];
    }
};

