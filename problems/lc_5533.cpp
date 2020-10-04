class Solution {
public:
    int minimumOneBitOperations(int n) {
        for (int i = 30; i >= 0; i--) {
            n ^= ((n >> 1) & (1 << i));
        }
        return n;
    }
};
