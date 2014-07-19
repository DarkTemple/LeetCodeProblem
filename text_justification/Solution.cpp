class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        vector<string>::iterator begin = words.begin();
        vector<string>::iterator end;
        while (begin != words.end()) {
            int totalChar = 0;
            int numOfChar = 0;
            end = begin;
            while (end != words.end()) {
                if (end != begin) totalChar++;
                totalChar += (*end).length();
                if (totalChar > L) {
                    break;
                }
                
                numOfChar += (*end).length();
                end++;
            }
            
            int numOfWord = end - begin;
            int numOfSpace = L - numOfChar;
            string line;
            bool isLastLine = end == words.end();
            for (vector<string>::iterator it = begin; it != end; it++) {
                int numOfGap = numOfWord - 1;
                int appendSpace;
                if (isLastLine) {
                    appendSpace = 1;
                } else if (numOfGap != 0) {
                    appendSpace = numOfSpace / numOfGap + (it - begin < (numOfSpace % numOfGap));
                }
                
                
                line += *it;
                if (it != end-1) line += string(appendSpace, ' ');
            }
            
            if (numOfWord == 1 || isLastLine) line += string(L - line.length(), ' ');
            ret.push_back(line);
            begin = end;
        }
        
        return ret;
    }
};