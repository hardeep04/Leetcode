class Solution {
public:
    int findClosest(int x, int y, int z) {
        int n = min(abs(x-z), abs(y-z));
        if(abs(y-z) == abs(x-z)) return 0;
        return n == abs(x-z) ? 1:2;
    }
};