class Solution {
public:
    int singleNumber(int A[], int n) {
        int tmpTable[32] = {0};
        for (int i=0; i<n; i++) {
            unsigned int number = (unsigned int)A[i];
            int index = 0;
            while (number) {
                if (number & 0x1){
                    tmpTable[index] += 1;
                }
                
                number >>= 1;
                index++;
            }
        }
        
        int ret = 0;
        for (int i=0; i<32; i++) {
            ret += (1 << i) * (tmpTable[i] % 3 != 0);
        }
        
        return ret;
    }
};