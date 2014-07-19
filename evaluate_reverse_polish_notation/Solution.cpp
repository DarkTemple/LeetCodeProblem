class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        for (int i=0; i<tokens.size(); i++) {
            string s = tokens[i];
            int num = 0;
            if (s.length() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*'|| s[0] == '/')) {
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                switch (s[0]) {
                    case '+':
                        num = a + b;
                        break;
                    case '-':
                        num = a - b;
                        break;
                    case '*':
                        num = a * b;
                        break;
                    case '/':
                        num = a / b;
                        break;
                    default:
                        break;
                }
            } else {
                num = stoi(s);
            }
            
            stack.push_back(num);
        }
        
        return stack.back();
    }
};
