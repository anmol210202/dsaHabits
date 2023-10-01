class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> s;
        int c=0;

        for(int i=0; i<n; i++){
            if(path[i]=='/') continue;
            string temp;
            while(i<n and path[i]!='/'){
                temp += path[i++];
            }

            if(temp == ".") continue;
            else if(temp == "..") {
                if(!s.empty()) s.pop();
            } else {
                s.push(temp);
            }

        }

        path.clear();

        while(!s.empty()){
            path = "/" + s.top() + path;
            s.pop();
        }

        return path.size() == 0 ? "/" : path;
    }
};
