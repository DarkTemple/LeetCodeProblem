class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(s[i]);
            } else {
                if (stack.empty()) return false;
                char t = stack.back();
                switch (c) {
                    case ')':
                        if (t != '(') return false;
                        break;
                    case ']':
                        if (t != '[') return false;
                        break;
                    case '}':
                        if (t != '{') return false;
                        break;
                    default:
                        break;
                }
                
                stack.pop_back();
            }
        }
        
        return stack.empty();
    }
};