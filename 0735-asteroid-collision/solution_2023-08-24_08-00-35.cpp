class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        for(auto &e:asteroids){
            bool explode = false;
            while(!ast.empty() and e<0 and ast.top()>0){
                if(abs(e)>abs(ast.top())) ast.pop();
                else if(abs(e)==ast.top()   ){
                    ast.pop();
                    explode=true;
                    break;
                }
                else {
                    explode=true;
                    break;
                }
            }
            if(!explode) ast.push(e);
        }
       vector<int> result(ast.size());
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = ast.top();
            ast.pop();
        }

        return result;
    }
};
