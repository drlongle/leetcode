class Solution {
public:
    string simplifyPath(string path) {
        string sPath;
        stack<string> pStack;
        
        int start = 0, end = 0;
        while(true) {
            start = path.find_first_not_of('/', end);
            if(start == string::npos) {
                break;
            }
            
            end = path.find_first_of('/', start);
            if(end == string::npos) {
                end = path.size();
            }
            
            string dirName = path.substr(start, end - start);
            if(dirName == ".") continue;
            else if(dirName == "..") {
                if( ! pStack.empty()) pStack.pop();
            } else {
                pStack.push(dirName);
            }
        }
        
        // Corner case !!
        if( pStack.empty()) sPath = "/";
        
        while( ! pStack.empty()) {
            string dir = pStack.top();
            pStack.pop();
            sPath = "/" + dir + sPath;
        }

        return sPath;
    }
};

