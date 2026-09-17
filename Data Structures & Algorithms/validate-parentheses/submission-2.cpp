class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(auto& i : s){
            if(i=='(' || i=='[' || i=='{'){
                stk.push(i);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if(stk.top()=='(' && i != ')'){
                    return false;
                }
                if(stk.top()=='[' && i != ']'){
                    return false;
                }
                if(stk.top()=='{' && i != '}'){
                    return false;
                }
                stk.pop();
            }
        }
        
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};
