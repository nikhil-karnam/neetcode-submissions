class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for(auto& i : tokens){
            if(i.size() == 1 && !std::isdigit(i[0])){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(i == "+"){
                    s.push(a+b);
                }
                else if(i == "-"){
                    s.push(a-b);
                }
                else if(i == "*"){
                    s.push(a*b);
                }
                else{
                    s.push(a/b);
                }
            }
            else{
                s.push(std::stoi(i));
            }
        }
        return s.top();
    }
};
