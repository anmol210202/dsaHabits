class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for(auto &e:tokens){
            if(e=="+"){
                int x=stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(x+y));
            }
            else if(e=="-"){
                int x=stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y-x));
            }
            else if(e=="*"){
                int x=stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(x*y));
            }
            else if(e=="/"){
                int x=stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y/x));
            }
            else {
                s.push(e);
            }
        }

        // cout<<s.size()<<endl;

        return stoi(s.top());
    }
};
