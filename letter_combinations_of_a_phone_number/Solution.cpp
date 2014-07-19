class Solution {
public:
    string num2Str(int i)
    {
        switch (i) {
            case 0:
            case 1:
                return "";
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
            default:
                return "";
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret(1, "");
        for (int i=0; i<digits.length(); i++) {
            int num = digits[i] - '0';
            int n = (int)ret.size();
            vector<string> newRet;
            for (int j=0; j<n; j++) {
                string prefix = ret[j];
                string appendCharStr = num2Str(num);
                for (int k=0; k<appendCharStr.length(); k++) {
                    newRet.push_back(prefix + appendCharStr[k]);
                }
            }
            
            ret.swap(newRet);
        }
        
        return ret;
    }
};